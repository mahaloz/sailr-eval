import os
import shutil
import sys
import time
from collections import defaultdict
from datetime import datetime
from pathlib import Path
import logging
from multiprocessing import Pool
from typing import List

import toml
from pyjoern import JoernClient, JoernServer, fast_cfgs_from_source
from pyjoern.mapping import cfg_root_node, correct_source_cfg_addrs

from sailreval import ALL_DECOMPILERS, ALL_METRICS, SAILR_DECOMPILERS, SAILR_METRICS, JOERNLESS_SERVER_METRICS
from sailreval.metrics import get_metric_function, POST_METRICS
from sailreval.metrics.ged_to_source import has_cfged_required_files, has_cfged_required_src_files
from sailreval.utils import bcolors, SAILR_DECOMPILATION_RESULTS_DIR, timeout, SAILR_MEASURE_RESULTS_DIR, WorkDirContext
from sailreval.decompilers.angr_dec import get_all_funcs
from sailreval.analysis.counting import decompilation_cache_to_results_format, collect_and_store_cache_data

from tqdm import tqdm

l = logging.getLogger(__name__)


def measure(filepath: Path, basename: str, metrics, functions, joern_port=9000, require_joern=True, client=None, **kwargs):
    if not metrics:
        return {}

    results = {}
    if not require_joern:
        client = None
    else:
        if client is None:
            client = JoernClient(filepath, port=joern_port, bin_name=basename)
    
    for metric in metrics:
        measure_func = get_metric_function(metric)
        results[metric] = measure_func(functions, client, **kwargs)

    return results

def _all_chached_or_joernless(basename: str, decompilers: list, metrics: list, cache_dir: Path):
    if decompilers is None or metrics is None:
        return False

    joernless_metrics = set(m for m in metrics if m in JOERNLESS_SERVER_METRICS)
    if len(joernless_metrics) == len(metrics):
        return True

    # some metrics is JOERNless, we must have a cache to be either not cached or joernless
    if cache_dir is None:
        l.debug("JOERN DIR IS NONE")
        return False

    cache_dir = Path(cache_dir)
    if not cache_dir.exists():
        l.debug("JOERN DIR does not exist!")
        return False

    cached_file = cache_dir / f"{basename}.toml"
    if not cached_file.exists():
        l.debug(f"JOERN cached filed does not exist: {cached_file}!")
        return False

    with open(cached_file, "r") as fp:
        cached_data = toml.load(fp)

    cached_metrics = set()
    for metric in metrics:
        for decompiler in decompilers:
            if metric not in cached_data.get(decompiler, {}):
                l.debug(f"Metric not in {decompiler} for {basename}, we must recompute metrics!")
                break
        else:
            cached_metrics.add(metric)

    l.debug(f"Cached metrics: {cached_metrics}")
    return len(cached_metrics.union(joernless_metrics)) == len(metrics)


def measure_files_with_joern_server(
    file_dir: Path, basename: str, decompilers=None, metrics=None, functions=None,
    cores=1, joern_port=9000, cache_dir=None, force_joern_skip=False, results_dir=None
):
    def _measure_files_with_joern_server():
        can_skip = _all_chached_or_joernless(basename, decompilers, metrics, cache_dir) or force_joern_skip
        if can_skip:
            l.debug(f"JOERN server not needed for {basename}")
            measure_files(file_dir, basename, decompilers=decompilers, metrics=metrics, functions=functions, cores=cores, joern_port=joern_port, require_joern=False, cache_dir=cache_dir)
        else:
            try:
                with JoernServer(port=joern_port):
                    measure_files(file_dir, basename, decompilers=decompilers, metrics=metrics, functions=functions, cores=cores, joern_port=joern_port, cache_dir=cache_dir)
            except Exception:
                return

    if results_dir is not None:
        with WorkDirContext(results_dir):
            _measure_files_with_joern_server()
    else:
        _measure_files_with_joern_server()


def _load_cache(cache_dir: Path, basename: str):
    if cache_dir is None:
        return {}

    cache_dir = Path(cache_dir).absolute()
    binary_cache = cache_dir / f"{basename}.toml"
    if not binary_cache.exists():
        return {}

    with open(binary_cache, "r") as fp:
        cached_results = toml.load(fp)

    return cached_results


def _cache_has_all_metrics(cache_results: dict, metrics: list, decompilers: list):
    for dec in decompilers:
        for metric in metrics:
            if metric not in cache_results.get(dec, {}):
                return False

    return True


def measure_files(file_dir: Path, basename: str, decompilers=None, metrics=None, functions=None, cores=1, joern_port=9000, single_metric_timeout=100, require_joern=True, cache_dir=None):
    decompilers = decompilers or ALL_DECOMPILERS
    metrics = metrics or ALL_METRICS
    #l.info(f"Starting evaluation on {basename} for metrics {metrics}")

    start_dt = datetime.now()
    file_dir = Path(file_dir).absolute()
    
    # get target files
    target_files = list(file_dir.rglob(f"*_{basename}.c"))
    target_binary = file_dir.joinpath(f"{basename}.o").absolute()
    all_source_types = [f"{dec}_{basename}.c" for dec in decompilers]
    for tfile in list(target_files):
        if tfile.name not in all_source_types:
            target_files.remove(tfile)

    # check the cache before doing expensive operations
    cached_results = _load_cache(cache_dir, basename)
    if _cache_has_all_metrics(cached_results, metrics, decompilers):
        l.info(f"All results are cached for {file_dir}/{basename}, skipping...")
        cached_results["binary"] = basename
        cached_results["total_time"] = 0
        cached_results["timeout"] = False
        with open(f"{basename}.toml", "w") as fp:
            toml.dump(cached_results, fp)

        return

    # generate default options for the set
    functions = functions or get_all_funcs(target_binary)
    if not functions:
        l.warning(f"Failed to find any functions for analysis and none were provided for {file_dir}/{basename}, using cache...")
        cache_dir = Path(cache_dir).absolute()
        binary_cache = cache_dir / f"{basename}.toml"
        if cache_dir is None or not binary_cache.exists():
            l.critical(f"Tried to use cache for functions on {file_dir}/{basename}, but none existed. Metrics will be skipped.")
            return

        with open(binary_cache, "r") as fp:
            cached_results = toml.load(fp)
        
        try:
            goto_metrics = cached_results[SAILR_DECOMPILERS.SOURCE_CODE][SAILR_METRICS.GOTO_COUNT]
        except KeyError:
            l.critical(f"Tried to use cache for functions on {file_dir}/{basename}, but no source with goto count existed")
            return

        functions = list(goto_metrics.keys()) 

    require_cfgs = any(
        m in metrics for m in (
            SAILR_METRICS.CFGED, SAILR_METRICS.GED_UPPERBOUND, SAILR_METRICS.GED_MAX, SAILR_METRICS.BLOCK_COUNT,
            SAILR_METRICS.CODE_COMPLEXITY, SAILR_METRICS.GED_EXACT
        )
    )

    # collect the source CFGs first if they are needed
    source_cfgs, dec_cfgs = {}, {}
    if require_cfgs and SAILR_DECOMPILERS.SOURCE_CODE in decompilers:
        for tfile in target_files:
            if tfile.name.startswith(SAILR_DECOMPILERS.SOURCE_CODE):
                if require_cfgs:
                    if has_cfged_required_src_files(tfile, target_binary):
                        linemaps_path = tfile.with_suffix(".linemaps")
                        extracted_cfgs = fast_cfgs_from_source(tfile.absolute())
                        if extracted_cfgs:
                            source_cfgs = correct_source_cfg_addrs(
                                extracted_cfgs,
                                linemaps_path,
                            )
                        else:
                            l.critical(f"JOERN failed to extract CFGS on {file_dir}/{basename}")
                            source_cfgs = {}
                    else:
                        l.critical(f"JOERN gave no source CFG for {file_dir}/{basename}, will skip all CFG metrics...")
                        source_cfgs = {}
                break

    results = defaultdict(dict)
    results["binary"] = basename
    had_timeout = False

    for target_file in target_files:
        filename = target_file.name
        dec_name = filename.split(f"_{basename}.c")[0]
        # skip targets that are not in requested decompiler set 
        if dec_name not in decompilers:
            continue

        # record which metric can be skipped
        cached_metric = []
        if dec_name in cached_results:
            cached_metric = list(cached_results[dec_name].keys())

        metrics_to_run = [m for m in metrics if m not in cached_metric]
        if metrics_to_run:
            # extract cfgs if needed
            if require_cfgs and has_cfged_required_files(target_file.absolute()):
                try:
                    dec_cfgs = fast_cfgs_from_source(target_file.absolute()) if dec_name != "source" else source_cfgs
                except Exception:
                    dec_cfgs = {}

            try:
                with timeout(seconds=single_metric_timeout*len(decompilers)):
                    results[dec_name] = measure(
                        target_file.absolute(), basename, metrics_to_run, functions, joern_port=joern_port,
                        dec_cfgs=dec_cfgs, source_cfgs=source_cfgs, binary_path=target_binary, decompiler=dec_name,
                        require_joern=require_joern
                    )
            except TimeoutError:
                l.warning(f"Measurement on {basename} for {decompilers} on {metrics} timedout! Will rerun once in next iter.")
                had_timeout = True

        # ready output
        if dec_name not in results:
            results[dec_name] = {}

        for metric in cached_metric:
            results[dec_name][metric] = cached_results[dec_name][metric]

    total_time = datetime.now().timestamp() - start_dt.timestamp()
    results["total_time"] = total_time
    results["timeout"] = had_timeout

    with open(f"{basename}.toml", "w") as fp:
        toml.dump(results, fp)

    #l.info(f"{bcolors.WARNING}{bcolors.BOLD}Completed evaluation on {basename} in {total_time} seconds.{bcolors.ENDC}.")


def _prep_measurement_directory(target_package_dir: Path, use_cache=True):
    """
    Verifies things exists, makes decompilation dir, may destroy old cache
    """
    sailr_dec_dir = target_package_dir.parent.absolute().joinpath(SAILR_DECOMPILATION_RESULTS_DIR).absolute()
    sailr_meas_dir = target_package_dir.absolute()
    if not sailr_meas_dir.exists():
        raise Exception(f"No sailr results dir for {target_package_dir}")

    all_binaries = list(sailr_dec_dir.glob("*.o"))
    binaries = all_binaries
    # if the user wants no cache
    if not use_cache and sailr_meas_dir is not None:
        # only do non_cached results
        for binary in all_binaries:
            basename = binary.with_suffix("").name
            if sailr_meas_dir.joinpath(f"{basename}.toml").exists():
                l.info(f"Found {basename} in measurements for {sailr_meas_dir} already, skipping...")
                continue

            binaries.append(binary)

    # destroy old cache if it exists (will recompute)
    old_cache = sailr_meas_dir / "cache"
    if old_cache.exists():
        shutil.rmtree(old_cache)
    res_cache_dir = old_cache
    os.mkdir(res_cache_dir)

    # recreate data in the cache based on prev results and the decompilers toml data
    res_cache_dir = collect_and_store_cache_data(sailr_meas_dir, sailr_dec_dir)

    # get the binary and the basename
    binaries_to_run = [] # (sailr_res_dir, sailr_dec_dir, basename, cache_dir)
    for binary_path in binaries:
        basename = binary_path.with_suffix("").name
        file_with_basename = list(sailr_dec_dir.rglob(f"*{basename}.c"))
        if not file_with_basename:
            l.warning(f"{bcolors.FAIL}{bcolors.BOLD} Binary {sailr_dec_dir}/{basename} either does not exist or has no source skipping... {bcolors.ENDC}")
            continue

        binaries_to_run.append((sailr_meas_dir, sailr_dec_dir, basename, res_cache_dir))

    return binaries_to_run


def batch_measure_targets(target_package_dirs: List[Path], decompilers=None, metrics=None, cores=1, first_port=9000, no_joern_server=False, use_cache=True):
    if metrics is not None:
        # remove all the post metrics since they are computed after eval
        metrics = [m for m in metrics if m not in POST_METRICS]

    l.info(f"Prepping batch measurement of {len(target_package_dirs)} directories...")
    jobs_no_port = [] # (sailr_res_dir, sailr_dec_dir, basename, cache_dir, joern_port)
    # first, extract all the binaries - source pairs
    for target_package_dir in target_package_dirs:
        # get jobs, which lack the joern port currently
        jobs_no_port += _prep_measurement_directory(target_package_dir, use_cache=use_cache)

    # now, we have all the jobs, but we needs port numbers
    jobs = [
        (sailr_res_dir, sailr_dec_dir, basename, cache_dir, first_port+i)
        for (i, (sailr_res_dir, sailr_dec_dir, basename, cache_dir)) in enumerate(jobs_no_port)
    ]

    # now, we can run the jobs
    l.info(f"Starting batch measurement of {len(jobs)} binaries across {len(target_package_dirs)} directories...")
    l.info(f"Evaluating with {cores} cores on {decompilers} with {metrics}, {'WITHOUT' if no_joern_server else 'with'} JOERN servers...")
    time.sleep(5)

    with Pool(processes=cores) as pool, tqdm(total=len(jobs), file=sys.stdout) as pbar:
        work = {}
        for job_args in jobs:
            sailr_res_dir, sailr_dec_dir, basename, cache_dir, joern_port = job_args
            w = pool.apply_async(
                measure_files_with_joern_server,
                args=(sailr_dec_dir, basename),
                kwds={"decompilers": decompilers, "metrics": metrics, "joern_port": joern_port, "cache_dir": cache_dir,
                      "force_joern_skip": no_joern_server, "results_dir": sailr_res_dir},
                callback=lambda _: pbar.update(1)
            )
            work[w] = job_args

        pool.close()
        for w, job_args in work.items():
            try:
                # every binary gets a max of 20 minutes
                w.get(timeout=60 * 20)
            except Exception as e:
                l.critical(f"Job {job_args} failed with exception {e}")
                pbar.update(1)
                continue

    l.info(f"Finished batch measurement of {len(jobs)} binaries across {len(target_package_dirs)} directories!")
