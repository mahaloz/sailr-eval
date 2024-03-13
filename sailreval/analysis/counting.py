import itertools
import os
import sys
from copy import deepcopy
from pathlib import Path
from collections import defaultdict
from typing import List, Dict, Tuple, Set
from multiprocessing import Pool
import logging
import statistics

from sailreval import ALL_DECOMPILERS, SAILR_DECOMPILERS, SAILR_METRICS, ALL_METRICS
from sailreval.utils import load_tomls_by_bin_name, bcolors
from sailreval.utils.sailr_target import SAILRTarget
from sailreval.utils.compile import DEFAULT_OPTIMIZATION_LEVELS, OPTIMIZATION_LEVELS

from tqdm import tqdm
import toml
from .visualization import save_data_as_markdown_table, plot_diff_barchar, plot_histogram

l = logging.getLogger(__name__)

DIFFABLE_METRICS = {SAILR_METRICS.BOOLEAN_COUNT, SAILR_METRICS.FUNC_CALLS, SAILR_METRICS.GOTO_COUNT, SAILR_METRICS.BLOCK_COUNT}
#STAT_TYPES = ("sum", "max", "mean", "median")
STAT_TYPES = ("sum", "mean", "median")


def _replace_function_name_with_known_symbol(func_name):
    replace_map = {
        'gettext': 'dcgettext'
    }

    try:
        f = replace_map[func_name]
    except KeyError:
        f = func_name

    return f


def unique_functions_in_set(fullnames: Set, data_by_pkg_name: Dict, decompiler, metrics):
    bad_funcs = set()
    for fullname in fullnames:
        split_name = fullname.split(".")
        bin_name, func_name = split_name[0], ".".join(split_name[1:])
        func_is_bad = False
        for pkg_name, data_by_bin_name in data_by_pkg_name.items():
            bin_data = data_by_bin_name.get(bin_name, None)
            if bin_data is None:
                #print(f"No source data for {pkg_name} on {bin_name}")
                func_is_bad = True
                break

            dec_data = bin_data.get(decompiler, None)
            if dec_data is None:
                #print(f"No decompiler data for {pkg_name} on {bin_name} for {decompiler}")
                func_is_bad = True
                break

            for metric, metric_data in dec_data.items():
                if metric not in metrics:
                    continue

                if func_name not in metric_data.keys():
                    #print(f"No metric data for {pkg_name} on {bin_name}.{func_name} for {metric} ")
                    func_is_bad = True
                    break

            if func_is_bad:
                break

        if func_is_bad:
            bad_funcs.add(fullname)

    unique_funcs = fullnames - bad_funcs
    return unique_funcs


def normalize_measurable_functions(data_by_pkg_name: Dict[str, Dict[str, Dict]], decompilers: List, metrics: List):
    """
    This function will return a list of fullnames (bin_name.func_name) that are common in every metric
    in every metric in every pkg in the data.

    Note: if you are collecting this data with the "SOURCE" decompiler, which is gathered using JOERN, then this data
    will actually already be unique and not need any more parsing!
    """

    # first, collect every possible fullname function in the first package which will act as our base for
    # removing functions that are not common across all packages
    first_pkg = data_by_pkg_name[list(data_by_pkg_name.keys())[0]]
    first_dec = decompilers[0]
    all_funcs = set()
    for bin_name, data_by_decompiler in first_pkg.items():
        for decompiler, data_by_metric in data_by_decompiler.items():
            if decompiler not in decompilers:
                continue

            for metric, data_by_func in data_by_metric.items():
                if metric not in metrics:
                    continue

                for func in data_by_func.keys():
                    all_funcs.add(f"{bin_name}.{func}")

    # while here, grab the functions unique to the source code only
    all_first_dec_funcs = set()
    if first_dec != SAILR_DECOMPILERS.SOURCE_CODE:
        l.warning(f"First decompiler is not source code... the output total functions will be of {first_dec}")

    for bin_name, data_by_decompiler in first_pkg.items():
        if first_dec not in data_by_decompiler:
            l.warning(f"Skipping {bin_name} becaused it lacked {first_dec} data...")
            continue 

        data_by_metric = data_by_decompiler[first_dec]
        for metric, data_by_func in data_by_metric.items():
            if metric not in metrics:
                continue

            for func in data_by_func.keys():
                all_first_dec_funcs.add(f"{bin_name}.{func}")
    unique_funcs_in_base = unique_functions_in_set(all_first_dec_funcs, data_by_pkg_name, first_dec, ["gotos"])

    # second, now that we have a list of all possible functions for analysis, we need to eliminate every
    # function that is not present in every package, for every decompiler, for every metric!
    funcs_not_common = set()
    failed_bin_for_dec = {dec: set() for dec in decompilers}
    for fullname in all_funcs:
        is_not_common = False
        split_name = fullname.split(".")
        bin_name, func_name = split_name[0], ".".join(split_name[1:])

        for pkg_name, data_by_bin_name in data_by_pkg_name.items():
            bin_data = data_by_bin_name.get(bin_name, None)
            if bin_data is None:
                is_not_common = True
                break
            
            for decompiler in decompilers:
                dec_data = bin_data.get(decompiler, None)
                if dec_data is None:
                    if bin_name not in failed_bin_for_dec[decompiler]:
                        l.critical(f"Decompiler {decompiler} failed to decompile the full binary {bin_name}")
                        failed_bin_for_dec[decompiler].add(bin_name) 

                    is_not_common = True
                    break 

                for metric in metrics:
                    data_by_func = dec_data.get(metric, None)
                    if data_by_func is None:
                        is_not_common = True
                        break 
                
                    if func_name not in data_by_func.keys():
                        is_not_common = True
                        break

                if is_not_common:
                    break

            if is_not_common:
                break

        if is_not_common:
            funcs_not_common.add(fullname)

    common_funcs = all_funcs - funcs_not_common
    return common_funcs, unique_funcs_in_base


def find_unique_functions_by_binary(data_by_bin_name: Dict, decompilers: List, metrics):
    metadata = {
        "total_functions_parsed_in_source": 0,
        "total_unique_functions_in_source": 0,
        "total_unique_functions_in_all_metrics": 0
    }

    # XXX: you need to change this sometimes
    exception_funcs = ['main', 'usage']
    skip_metrics = []

    # first, collect a set of seen function symbols that are unique
    seen_source_func_names = set()
    unique_source_func_fullnames = set()
    first_dec = SAILR_DECOMPILERS.SOURCE_CODE if SAILR_DECOMPILERS.SOURCE_CODE in decompilers \
        else decompilers[0]
    for bin_name, bin_data in data_by_bin_name.items():
        source_data = bin_data.get(first_dec, None)
        if source_data is None:
            continue

        # we only will check the first metric for each binary
        for metric, metric_data in source_data.items():
            for func in metric_data.keys():
                metadata["total_functions_parsed_in_source"] += 1

                # don't record seen func names
                if func in seen_source_func_names and func not in exception_funcs:
                    continue

                seen_source_func_names.add(func)
                unique_source_func_fullnames.add(f"{bin_name}.{func}")

    # we now have a list of unique symbols, but now we need to verify that each of these symbols appear
    # as a recorded key for every metric for every decompiler
    metadata["total_unique_functions_in_source"] = len(unique_source_func_fullnames)
    delinquent_funcs = set()
    for fullname in unique_source_func_fullnames:
        split_name = fullname.split(".")
        binary, func = split_name[0], ".".join(split_name[1:])

        bin_data = data_by_bin_name.get(binary, None)
        if bin_data is None:
            delinquent_funcs.add(fullname)
            continue

        if any([dec not in bin_data.keys() for dec in decompilers]):
            delinquent_funcs.add(fullname)
            #print(f"A decompiler is missing in {binary}, skipping {fullname}...")
            continue

        is_delinquent = False
        for dec, dec_data in bin_data.items():
            if dec not in decompilers:
                continue

            for metric, metric_data in dec_data.items():
                if metric in skip_metrics:
                    continue

                if metric not in metrics:
                    continue

                if func not in metric_data.keys():
                    #print(f"{func} not in {metric} for {binary} on {dec}")
                    is_delinquent = True
                    break

            # leave early if a delinquent is found
            if is_delinquent:
                break

        if is_delinquent:
            delinquent_funcs.add(fullname)

    # the list of unique functions found in all decompiler outputs is the difference of the two sets
    unique_funcs_by_binary = unique_source_func_fullnames - delinquent_funcs

    # finally, remove every single function that may not exist in the final
    remove_fullnames = set()
    for fullname in unique_funcs_by_binary:
        split_name = fullname.split(".")
        binary, func_name = split_name[0], ".".join(split_name[1:])
        bin_data = data_by_bin_name[binary]

        for decompiler in decompilers:
            dec_data = bin_data.get(decompiler, None)
            if decompiler is None:
                remove_fullnames.add(fullname)
                break

            should_break = True
            for metric in metrics:
                met_data = dec_data.get(metric, None)
                if met_data is None:
                    remove_fullnames.add(fullname)
                    break

                met_val = met_data.get(func_name, None)
                if met_val is None:
                    remove_fullnames.add(fullname)
                    break
            else:
                should_break = False

            if should_break:
                break
        else:
            pass

    unique_funcs_by_binary = unique_funcs_by_binary - remove_fullnames
    metadata["total_unique_functions_in_all_metrics"] = len(unique_funcs_by_binary)
    return unique_funcs_by_binary, metadata


def filter_functions_by_block_size(fullname_funcs, data_by_pkg, decompilers, max_size=None, min_size=None):
    if max_size is None and min_size is None:
        return fullname_funcs

    bad_functions = set()
    for fullname in fullname_funcs:
        split_name = fullname.split(".")
        binary, func_name = split_name[0], ".".join(split_name[1:])

        for pkg, data_by_bin_name in data_by_pkg.items():
            bin_data = data_by_bin_name[binary]

            for decompiler in decompilers:
                dec_data = bin_data[decompiler]
                func_size = dec_data.get(SAILR_METRICS.BLOCK_COUNT, {}).get(func_name, None)
                if func_size is None or \
                        (min_size is not None and func_size < min_size) or \
                        (max_size is not None and func_size > max_size):
                    bad_functions.add(fullname)
                    break

    return fullname_funcs - bad_functions


def summarize_directory(
    data_by_binary: Path, unique_functions_by_binary, funcs_in_src, decompilers: List, metrics: List, unique_funcs=None,
    min_func_size=None, max_func_size=None, show_stats=False, show_diffs=False
):
    from sailreval.metrics import POST_METRICS
    summary = {dec: defaultdict(int) for dec in decompilers}
    summary["metadata"] = {}
    summary["metadata"]["total_unique_functions_in_src"] = len(funcs_in_src)
    summary["metadata"]["total_unique_functions_in_all_metrics"] = len(unique_functions_by_binary)
    listed_metrics = {dec: defaultdict(list) for dec in decompilers}
    data_by_metric = {dec: defaultdict(dict) for dec in decompilers}
    non_post_metrics = [m for m in metrics if m not in POST_METRICS]
    for fullname in unique_functions_by_binary:
        split_name = fullname.split(".")
        binary, func_name = split_name[0], ".".join(split_name[1:])
        bin_data = data_by_binary[binary]
        
        # filter out too-high CFGED functions
        #skip = False
        #if SAILR_METRICS.CFGED in metrics:
        #    vals_for_dec_set = set()
        #    for decompiler in decompilers:
        #        if decompiler == SAILR_DECOMPILERS.SOURCE_CODE:
        #            continue
        #        met_val = bin_data[decompiler][SAILR_METRICS.CFGED][func_name]
        #        vals_for_dec_set.add(int(float(met_val)))
        #    if min(vals_for_dec_set) >= 800:
        #        skip = True
        #        skip = False

        #if skip:
        #    continue

        # key errors SHOULD NEVER happen now, if it does, we should crash
        for decompiler in decompilers:
            dec_data = bin_data[decompiler]
            for metric in non_post_metrics:
                was_set = False
                met_val = dec_data[metric][func_name]
                if isinstance(met_val, dict):
                    int_val = sum(list(met_val.values()))
                    data_by_metric[decompiler][metric][fullname] = met_val
                    was_set = True
                elif isinstance(met_val, str):
                    # this is likely CFGED or GED
                    int_val = int(float(met_val))
                elif isinstance(met_val, int):
                    int_val = met_val
                elif isinstance(met_val, float):
                    int_val = met_val
                    if metric != SAILR_METRICS.DEC_TIME:
                        int_val = int(met_val)
                else:
                    raise Exception(f"This should not be possible. Bad metric: {metric}")

                summary[decompiler][metric] += int_val
                listed_metrics[decompiler][metric].append(int_val)
                if not was_set:
                    data_by_metric[decompiler][metric][fullname] = int_val

    #
    # Diffs!
    #

    if show_diffs:
        for metric in metrics:
            if metric not in DIFFABLE_METRICS:
                continue

            for dec in decompilers:
                listed_metrics[dec][f"diff_{metric}"] = _compute_metric_diff_to_src(metric, dec, data_by_metric)

    #
    # Post Metrics (metrics computed after first analysis)
    #

    from sailreval.metrics.post_metrics import run_post_metrics

    listed_metrics = run_post_metrics([m for m in metrics if m in POST_METRICS], listed_metrics)

    #
    # Mode, Median, and Max.
    #

    for dec in decompilers:
        for metric in metrics:
            if metric not in metrics:
                continue

            metric_names = [metric] if metric not in DIFFABLE_METRICS else [metric, f"diff_{metric}"]
            for metric_name in metric_names:
                metric_list = listed_metrics[dec].get(metric_name, None)
                if not metric_list:
                    if ("diff" in metric_name and show_diffs) or "diff" not in metric_name:
                        l.warning(f"Metric list {metric_name} is empty, skipping statistics on it...")
                    continue

                # rename it to be sum to be clearer
                if metric_name in summary[dec]:
                    del summary[dec][metric_name]
                summary[dec][f"{metric_name}_sum"] = round(sum(metric_list), ndigits=2)

                if show_stats:
                    summary[dec][f"{metric_name}_mean"] = round(statistics.mean(metric_list), ndigits=2)
                    summary[dec][f"{metric_name}_median"] = round(statistics.median(metric_list), ndigits=2)
                    summary[dec][f"{metric_name}_max"] = round(max(metric_list), ndigits=2)

    print(f"{bcolors.BOLD}{bcolors.OKGREEN}======= START SUMMARY ======={bcolors.ENDC}")
    print(toml.dumps(summary))
    print(f"{bcolors.BOLD}{bcolors.OKGREEN}======= END SUMMARY ======={bcolors.ENDC}")

    # XXX: disabled for now
    # save data as various formats
    #decs_by_metric = defaultdict(dict)
    #listed_metrics = dict(listed_metrics)
    #for dec, metric_datas in listed_metrics.items():
    #    for metric, mdata in metric_datas.items():
    #        decs_by_metric[metric][dec] = mdata

    #if SAILR_DECOMPILERS.ANGR_SAILR in decompilers and SAILR_DECOMPILERS.IDA in decompilers and \
    #        SAILR_METRICS.CFGED in metrics:
    #    l.info(f"Plotting difference...")
    #    plot_diff_barchar(decs_by_metric, "cfged", ["angr_sailr", "ida"])

    return summary, listed_metrics


def _veryify_toml_dir_paths(toml_dir_paths, decompilers, metrics):
    # sanity check metrics and decompilers!
    if not decompilers or any([dec not in ALL_DECOMPILERS for dec in decompilers]):
        raise Exception(f"Provided decompilers: {decompilers} not in supported list of decompilers: {ALL_DECOMPILERS}")
    if not metrics or any([m not in ALL_METRICS for m in metrics]):
        raise Exception(f"Provided metrics: {metrics} not in supported list of metrics: {ALL_METRICS}")

    # sanity check toml dir paths
    for toml_dir_path in toml_dir_paths:
        toml_dir_path = Path(toml_dir_path).absolute()
        if not toml_dir_path.exists():
            raise Exception(f"Provided toml directory: {toml_dir_path} does not exist!")


def summarize_data_tomls(
    toml_dir_paths: List[Path], decompilers: List, metrics: List, unique_funcs=None, min_func_size=None,
    max_func_size=None, show_stats=False, show_diffs=False, report_func_order=False
):
    from sailreval.metrics import POST_METRICS
    _veryify_toml_dir_paths(toml_dir_paths, decompilers, [m for m in metrics if m not in POST_METRICS])
    
    # load every package, which can be one, into a dict
    data_by_pkg = {}
    for toml_dir_path in toml_dir_paths:
        for opt_level in OPTIMIZATION_LEVELS:
            if opt_level in str(toml_dir_path):
                break
        else:
            raise ValueError("This path has no optimization level!")
        
        save_name = toml_dir_path.name
        if toml_dir_path.name == "sailr_measured":
            save_name = toml_dir_path.parent.name

        short_name = f"{opt_level}/{save_name}"
        if short_name in data_by_pkg:
            short_name = f"{toml_dir_path.parent.parent.parent.name}/{opt_level}/{save_name}"
        
        data_by_pkg[short_name] = load_tomls_by_bin_name(toml_dir_path)

    # normalize data by assuring each function exists in each: pkg, decompiler, metric, func!
    print(f"Normalizing data for: {data_by_pkg.keys()}")
    unique_functions_by_binary, funcs_in_src = normalize_measurable_functions(
        data_by_pkg, decompilers, [m for m in metrics if m not in POST_METRICS]
    )

    # filter all functions by block size if necessary
    if min_func_size is not None or max_func_size is not None:
        unique_functions_by_binary = filter_functions_by_block_size(
            unique_functions_by_binary, data_by_pkg, decompilers, max_size=max_func_size, min_size=min_func_size
        )

    summary = {}
    listed_metrics = {}
    unique_functions_by_binary = sorted(list(unique_functions_by_binary))
    for pkg, data_by_binary in data_by_pkg.items():
        l.info(f"Summarizing... {pkg}")
        _summary, _listed_metrics = summarize_directory(
            data_by_binary, unique_functions_by_binary, funcs_in_src, decompilers, metrics, unique_functions_by_binary,
            show_stats=show_stats, show_diffs=show_diffs,
        )
        summary[pkg] = _summary
        listed_metrics[pkg] = _listed_metrics
        if report_func_order:
            listed_metrics[pkg]["func_order"] = [f for f in unique_functions_by_binary]


    l.info("Saving markdown table...")
    print(save_data_as_markdown_table(summary, show_stats=show_stats))

    return summary, listed_metrics


def summarize_sailr_targets(
    sailr_targets: List[SAILRTarget], decompilers: List, metrics: List, opt_levels=DEFAULT_OPTIMIZATION_LEVELS,
    unique_funcs=None, min_func_size=None, max_func_size=None, show_stats=False, show_diffs=False,
):
    toml_dirs_by_pkg = defaultdict(list)
    for sailr_target in sailr_targets:
        for opt_level in opt_levels:
            toml_dirs_by_pkg[sailr_target.package_name].append(Path(f"./results/{opt_level}/{sailr_target.package_dir}/sailr_measured"))

    # sanity check
    all_toml_dir_paths = list(itertools.chain.from_iterable(toml_dirs_by_pkg.values()))
    _veryify_toml_dir_paths(all_toml_dir_paths, decompilers, metrics)

    summaries_by_opt = defaultdict(dict)
    listed_metrics_by_opt = defaultdict(dict)
    full_summary_doc = ""
    for pkg_name, toml_dirs in toml_dirs_by_pkg.items():
        _summary, _listed_metrics = summarize_data_tomls(
            toml_dirs, decompilers, metrics, unique_funcs=unique_funcs, min_func_size=min_func_size,
            max_func_size=max_func_size,
        )
        full_summary_doc += save_data_as_markdown_table(deepcopy(_summary), show_stats=show_stats)
        #pkg_name = list(_summary.keys())[0]
        for name_with_opt in _summary:
            for opt_level in opt_levels:
                if opt_level in name_with_opt:
                    break
            else:
                raise ValueError("Opt not in package name")

            summaries_by_opt[opt_level][pkg_name] = _summary[name_with_opt]
            listed_metrics_by_opt[opt_level][pkg_name] = _listed_metrics[name_with_opt]

    with open("full_summary.md", "w") as fp:
        fp.write(full_summary_doc)

    big_summary = {}
    for opt in opt_levels:
        big_summary[opt] = {dec: defaultdict(int) for dec in decompilers + ['metadata']}
    for opt, pkg_data in summaries_by_opt.items():
        for pkg_name, summary in pkg_data.items():
            for dec, data in summary.items():
                for m, mdata in data.items():
                    big_summary[opt][dec][m] += mdata
    
    #
    # Big Stats!
    #

    listed_metrics = {}
    for opt in opt_levels:
        listed_metrics[opt] = {dec: defaultdict(list) for dec in decompilers}
    for opt, pkg_data in listed_metrics_by_opt.items():
        for pkg_name, lmetrics in pkg_data.items():
            for dec in decompilers:
                for metric in metrics:
                    listed_metrics[opt][dec][metric] += lmetrics[dec][metric]

        for dec in decompilers:
            for metric in metrics:
                if metric not in metrics:
                    continue

                metric_names = [metric] if metric not in DIFFABLE_METRICS else [metric, f"diff_{metric}"]
                for metric_name in metric_names:
                    metric_list = listed_metrics[opt][dec].get(metric_name, None)
                    if not metric_list:
                        if ("diff" in metric_name and show_diffs) or "diff" not in metric_name:
                            l.warning(f"Metric list {metric_name} is empty, skipping statistics on it...")
                        continue

                    # rename it to be sum to be clearer
                    if metric_name in big_summary[opt][dec]:
                        del big_summary[opt][dec][metric_name]
                    big_summary[opt][dec][f"{metric_name}_sum"] = round(sum(metric_list), ndigits=2)

                    if show_stats:
                        big_summary[opt][dec][f"{metric_name}_mean"] = round(statistics.mean(metric_list), ndigits=2)
                        big_summary[opt][dec][f"{metric_name}_median"] = round(statistics.median(metric_list), ndigits=2)
                        big_summary[opt][dec][f"{metric_name}_max"] = round(max(metric_list), ndigits=2)


    first_opt = opt_levels[0]
    
    #fixed_summary = {}
    #for opt in opt_lvels:
    #    fixed_summary = {dec: {} for dec in decompilers + ['metadata']}
    #for opt, pkg_data in big_summary.items():
    #    for dec, dec_data in pkg_data.items():
    #        for met, met_data in dec_data.items():
    #            fixed_summary[opt][dec][met] = met_data


    #final_summary = {f"{len(summaries_by_opt[first_opt].keys())} Packages across {len(opt_levels)} opt levels": fixed_summary}
    print(save_data_as_markdown_table(big_summary, show_stats=show_stats))
    return big_summary, listed_metrics_by_opt

#
# Diff Metric Computation
#


def _compute_metric_diff_to_src(metric, dec, data_by_metric):
    dec_metric_data = data_by_metric[dec][metric]
    src_metric_data = data_by_metric[SAILR_DECOMPILERS.SOURCE_CODE][metric]
    diff_list = []

    # special case for function diffing
    if metric == SAILR_METRICS.FUNC_CALLS:
        return _compute_dup_diff(dec, data_by_metric)

    for func, data in src_metric_data.items():
        if isinstance(data, dict):
            src_val = sum(list(data.values()))
        else:
            src_val = data

        dec_val = dec_metric_data.get(func, 0)
        if isinstance(dec_val, dict):
            dec_val = sum(list(dec_val.values()))

        diff_list.append(abs(src_val - dec_val))

    return diff_list


def _compute_dup_diff(dec, data_by_metric):
    dec_metric_data = data_by_metric[dec][SAILR_METRICS.FUNC_CALLS]
    source_metric_data = data_by_metric[SAILR_DECOMPILERS.SOURCE_CODE][SAILR_METRICS.FUNC_CALLS]
    diff_list = []

    for top_func, data in source_metric_data.items():
        for func_call, val in data.items():
            dec_val = dec_metric_data[top_func].get(func_call, 0)
            diff_list.append(abs(val - dec_val))

    return diff_list

#
# Cache to Results tomls
#


def find_decompiler_cache_files(decompilation_cache: Path) -> List[Tuple[Path, str, str]]:
    """
    Output: [(toml_path, decompiler, binary_name)]
    """
    decompilation_cache = Path(decompilation_cache)
    partial_tomls = [p.absolute() for p in decompilation_cache.glob("*.toml")]
    decompiler_cache_files = []
    for toml_path in partial_tomls:
        for dec_name in ALL_DECOMPILERS:
            if toml_path.name.startswith(dec_name + "_"):
                split_data = toml_path.name.split(dec_name + "_")
                if len(split_data) > 1:
                    bin_name = split_data[-1].split(".toml")[0]
                    break
        else:
            # decompiler name was not found for this target
            continue

        decompiler_cache_files.append((toml_path, dec_name, bin_name))

    return decompiler_cache_files


def collect_and_store_cache_data(measurement_dir: Path, decompilation_cache: Path):
    measurement_dir = Path(measurement_dir)
    toml_paths = [p.absolute() for p in measurement_dir.glob("*.toml")]
    prev_meas_data_by_bin = defaultdict(dict)
    dec_cache_data_by_binary = decompilation_cache_to_results_format(decompilation_cache)
    for toml_path in toml_paths:
        with open(toml_path, "r") as fp:
            toml_data = toml.load(fp)

        bin_name = toml_data['binary']
        for dec in ALL_DECOMPILERS:
            if dec in toml_data:
                prev_meas_data_by_bin[bin_name][dec] = toml_data[dec]

    # base all initial cache on decompiler directly caches measurements
    final_data = dec_cache_data_by_binary.copy()
    for bin_name, data_by_decompiler in dec_cache_data_by_binary.items():
        for dec in data_by_decompiler.keys():
            meas_metric_data = prev_meas_data_by_bin.get(bin_name, {}).get(dec, None)
            if not meas_metric_data:
                continue

            for metric, mdata in meas_metric_data.items():
                if mdata:
                    final_data[bin_name][dec][metric] = mdata

    # final data is computed, now we save it
    cache_dir = measurement_dir / "cache"
    cache_dir = cache_dir.absolute()
    if not cache_dir.exists():
        cache_dir.mkdir()

    for bin_name, data_by_decompiler in final_data.items():
        data_by_decompiler['binary'] = bin_name
        with open(cache_dir / f"{bin_name}.toml", "w") as fp:
            toml.dump(data_by_decompiler, fp)

    return cache_dir


def decompilation_cache_to_results_format(decompilation_cache: Path, delete_partials=False):
    tdata_by_binary = defaultdict(dict)
    for toml_path, dec_name, bin_name in find_decompiler_cache_files(decompilation_cache):
        with open(toml_path, "r") as fp:
            if dec_name == "ghidra":
                try:
                    toml_data = toml.load(fp)  
                except Exception as e:
                    l.critical(f"Failed to load a ghidra file {toml_path} because {e}")
                    continue
            else:
                toml_data = toml.load(fp)

        # XXX: add source different from other decompilers, since it's not flipped
        if dec_name == SAILR_DECOMPILERS.SOURCE_CODE:
            tdata_by_binary[bin_name][SAILR_DECOMPILERS.SOURCE_CODE] = toml_data
            continue

        data_by_metric = defaultdict(dict)
        for func, metrics in toml_data.items():
            for metric, mdata in metrics.items():
                data_by_metric[metric][func] = mdata

        tdata_by_binary[bin_name][dec_name] = data_by_metric

    for bin_name, toml_data in tdata_by_binary.items():
        toml_data['binary'] = bin_name
        with open(decompilation_cache / f"{bin_name}.toml", "w") as fp:
            toml.dump(toml_data, fp)

    return tdata_by_binary

#
# Metric bigger counting
#

def find_functions_with_bigger_metric(data, decompilers, metric, base_is_zero=False, diff_amt=0):
    def _format_number(num):
        if isinstance(num, str):
            return int(float(num))

        return num

    #
    # do it!
    #

    old_dec = decompilers[0]
    new_dec = decompilers[1]
    functions = set()

    for bin_name, bin_data in data.items():
        old_goto = bin_data.get(old_dec, {}).get(metric, None)
        new_goto = bin_data.get(new_dec, {}).get(metric, None)
        if new_goto is None or old_goto is None:
            continue

        for func, old_score in old_goto.items():
            if func not in new_goto:
                continue

            old_score = _format_number(old_score)
            new_score = _format_number(new_goto[func])
            if (base_is_zero and old_score == 0) or not base_is_zero:
                if new_score > old_score and new_score - old_score >= diff_amt:
                    #print(f"{bin_name}.{func}: {new_dec}:{new_score} > {old_dec}:{old_score}")
                    functions.add(f"{bin_name}.{func}")

    return functions


#
# Switch counting
#

def _find_functions_with_switches(source_path: Path, port):
    source_name = source_path.name.split(".c")[0]

    from pyjoern import JoernServer, JoernClient
    with JoernServer(port=port):
        client = JoernClient(source_path, port=port)
        functions = client.functions_with_switches()

    return [f"{source_name}.{func}" for func in functions]


def find_functions_with_switches(source_paths: List[Path], cores=12):
    with Pool(processes=cores) as pool, tqdm(total=len(source_paths)) as pbar:
        work = []

        for i, src_path in enumerate(source_paths):
            if not src_path.exists():
                pbar.update(1)
                continue

            work.append(pool.apply_async(
                _find_functions_with_switches,
                args=(src_path, 9000+i),
                callback=lambda _: pbar.update(1)
            ))


        pool.close()
        result = []
        for w in work:
            try:
                funcs = w.get(timeout=240)
            except:
                pbar.update(1)
                continue

            result += funcs

        with open("results.toml", "w") as fp:
            toml.dump({"switch-functions": result}, fp)
