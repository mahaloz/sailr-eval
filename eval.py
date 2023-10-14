#!/usr/bin/env python3
import argparse
import os
import shutil
from pathlib import Path
import time
from typing import List, Dict, Tuple
import logging
from collections import defaultdict

import toml

from sailreval import ALL_DECOMPILERS, ALL_METRICS, SAILR_METRICS, SAILR_DECOMPILERS
from sailreval.utils import WorkDirContext, SAILR_COMPILATION_RESULTS_DIR, SAILR_MEASURE_RESULTS_DIR, SAILR_DECOMPILATION_RESULTS_DIR
from sailreval.utils.sailr_target import SAILRTarget
from sailreval.utils.compile import (
    compile_and_copy_clean_files, BASE_FLAGS, clean_and_update_source_from_i, OPTIMIZATION_LEVELS,
    DEFAULT_OPTIMIZATION_LEVELS
)
from sailreval.analysis.counting import summarize_data_tomls, decompilation_cache_to_results_format, \
    summarize_sailr_targets

l = logging.getLogger(__name__)

#
# USEFUL CONSTANTS
#

# location of this running program
FILE_LOCATION = Path(__file__).parent.absolute()


def iterate_all_targets(target_names, opt_levels=OPTIMIZATION_LEVELS, results_dir="./results") -> \
        Dict[str, Dict[str, Tuple[SAILRTarget, Path, Path, Path, Path]]]:
    """
    Returns: [target_name] = (sailr_target, sailr_target_dir, sailr_compile_dir, sailr_decompile_dir, sailr_measure_dir)
    """
    out = defaultdict(dict)
    for target_name in target_names:
        for opt_level in opt_levels:
            sailr_target = SAILRTarget.from_toml(f"./targets/{target_name}.toml")
            sailr_target_dir = Path(f"{results_dir}/{opt_level}/").joinpath(sailr_target.package_dir).absolute()
            sailr_compile_dir = sailr_target_dir.joinpath(SAILR_COMPILATION_RESULTS_DIR).absolute()
            sailr_decompile_dir = sailr_target_dir.joinpath(SAILR_DECOMPILATION_RESULTS_DIR).absolute()
            sailr_measure_dir = sailr_target_dir.joinpath(SAILR_MEASURE_RESULTS_DIR).absolute()

            out[opt_level][sailr_target.package_name] = (
                (sailr_target, sailr_target_dir, sailr_compile_dir, sailr_decompile_dir, sailr_measure_dir)
            )

    return out


def load_target(target_path):
    with open(target_path, "r") as fp:
        out = toml.load(fp)

    return out


def get_all_targets():
    return [
        name.split(".toml")[0] for name in os.listdir("./targets")
        if name.endswith(".toml")
    ]


def archive_targets(
    targets, opt_levels=DEFAULT_OPTIMIZATION_LEVELS, results_dir="./results",
    delete_dec=(SAILR_DECOMPILERS.ANGR_SAILR, SAILR_DECOMPILERS.ANGR_PHOENIX, SAILR_DECOMPILERS.ANGR_COMB, SAILR_DECOMPILERS.ANGR_DREAM)
):
    timestamp = str(int(time.time()))
    with WorkDirContext(FILE_LOCATION):
        targets_info = iterate_all_targets(targets, opt_levels=opt_levels, results_dir=results_dir)
        for opt_level, target_data in targets_info.items():
            for target_name, target_info in target_data.items():
                sailr_target, _, _, dec_dir, meas_dir = target_info

                # move the old results
                if meas_dir.exists():
                    shutil.move(meas_dir.absolute(), meas_dir.with_name(f"{SAILR_MEASURE_RESULTS_DIR}_{timestamp}").absolute())
                else:
                    l.warning(f"Measurement directory does not exist for {opt_level}/{target_name}, skipping...")

                # copy the previous decompilation
                if dec_dir.exists():
                    #shutil.copytree(dec_dir, dec_dir.with_name(f"{SAILR_DECOMPILATION_RESULTS_DIR}_{timestamp}"))

                    # delete outdated decompilation results (only angr decompilers)
                    for dec in delete_dec:
                        for dec_file in dec_dir.glob(f"{dec}_*"):
                            dec_file.unlink()
                else:
                    l.warning(f"Decompilation directory does not exist for {opt_level}/{target_name}, skipping...")


def compile_targets(targets, cflags, cores, cc, cxx, opt_levels=DEFAULT_OPTIMIZATION_LEVELS, clean=False):
    with WorkDirContext(FILE_LOCATION):
        for target_name in targets:
            sailr_target = SAILRTarget.from_toml(f"./targets/{target_name}.toml")
            compile_and_copy_clean_files(sailr_target, cflags, cores, opt_levels=opt_levels, cc=cc, cxx=cxx, clean=clean)


def decompile_targets(targets, decompilers, cores, opt_levels=DEFAULT_OPTIMIZATION_LEVELS, clean=False, symboless=False):
    from sailreval.decompilers import batch_decompile_and_move_obj_files
    logging.getLogger("cle").setLevel(logging.ERROR)
    with WorkDirContext(FILE_LOCATION):
        target_dir_path_tuples = []
        for target_name in targets:
            for opt_level in opt_levels:
                sailr_target = SAILRTarget.from_toml(f"./targets/{target_name}.toml")
                sailr_target_dir = Path(f"./results/{opt_level}/").joinpath(sailr_target.package_dir).absolute()

                if SAILR_DECOMPILERS.SOURCE_CODE in decompilers:
                    sailr_compile_dir = sailr_target_dir.joinpath(SAILR_COMPILATION_RESULTS_DIR).absolute()
                    if not sailr_compile_dir.exists() and not sailr_target.skip_file_copy:
                        l.critical(f"Trying to copy and clean source, but the compile dir does not exist: {sailr_compile_dir}")
                        return

                    clean_and_update_source_from_i(sailr_compile_dir, sailr_target)

                target_dir_path_tuples.append((sailr_target_dir, sailr_target))
            #decompile_and_move_obj_files(sailr_target_dir, decompilers, cores, clean=clean)

        batch_decompile_and_move_obj_files(target_dir_path_tuples, decompilers=decompilers, cores=cores, clean=clean, symboless=symboless)
        for path, _ in target_dir_path_tuples:
            decompilation_cache_to_results_format(path / SAILR_DECOMPILATION_RESULTS_DIR)


def measure_targets(targets, decompilers, metrics, cores, opt_levels=DEFAULT_OPTIMIZATION_LEVELS, clean=False, ignored_func_size=None):
    from sailreval.analysis.measure import batch_measure_targets
    start_time = time.time()
    logging.getLogger("cle").setLevel(logging.ERROR)

    results_dirs = []
    with WorkDirContext(FILE_LOCATION):
        for target_name in targets:
            for opt_level in opt_levels:
                sailr_target = SAILRTarget.from_toml(f"./targets/{target_name}.toml")
                sailr_target_dir = Path(f"./results/{opt_level}/").joinpath(sailr_target.package_dir).absolute()

                # clean and make SAILR results output location
                sailr_results_dir = sailr_target_dir.joinpath(SAILR_MEASURE_RESULTS_DIR).absolute()
                results_dirs.append(sailr_results_dir)
                if clean and sailr_results_dir.exists():
                    shutil.rmtree(sailr_results_dir)
                    os.mkdir(sailr_results_dir)
                elif not sailr_results_dir.exists():
                    os.mkdir(sailr_results_dir)

    batch_measure_targets(
        results_dirs, decompilers=decompilers, metrics=metrics, cores=cores,
        first_port=9000, no_joern_server=True,
    )
    merge_results(results_dirs, decompilers, metrics, min_func_size=ignored_func_size)


def merge_results(results_dirs: List[Path], decompilers: List[str], metrics: List[str], output_path="./results.toml", **kwargs):
    pathed_results_dirs = [
        Path(results_dir).absolute() for results_dir in results_dirs
    ]
    summary, _ = summarize_data_tomls(pathed_results_dirs, decompilers, metrics, **kwargs)
    with open(output_path, "w") as fp:
        toml.dump(summary, fp)

    l.info(f"Merged results file saved to {output_path}")


def summarize_many_targets(targets: List[str], decompilers: List[str], metrics: List[str], output_path="./results.toml", opt_levels=DEFAULT_OPTIMIZATION_LEVELS,  **kwargs):
    sailr_targets = list()
    with WorkDirContext(FILE_LOCATION):
        for target_name in targets:
            sailr_target = SAILRTarget.from_toml(f"./targets/{target_name}.toml")
            sailr_targets.append(sailr_target)


        summary, _ = summarize_sailr_targets(sailr_targets, decompilers, metrics, opt_levels=opt_levels, **kwargs)

#
# Entry Point
#


def main(args):
    if args.update_path is not None:
        path = os.getenv("PATH")
        path = f"{args.update_path}:{path}"
        os.putenv("PATH", path)

    if args.compile is not None or args.full_eval:
        targets = args.compile or get_all_targets()
        compile_targets(targets, args.cflags, args.cores, args.cc, args.cxx, opt_levels=args.opt_levels)

    if args.decompile is not None or args.full_eval:
        targets = args.decompile or get_all_targets()
        decompile_targets(targets, args.use_dec, args.cores, clean=args.clean, opt_levels=args.opt_levels, symboless=args.symboless)

    if args.measure is not None or args.full_eval:
        targets = args.measure or get_all_targets()
        measure_targets(targets, args.use_dec, args.use_metric, args.cores,
                        clean=args.clean if args.clean is not None else False,
                        ignored_func_size=args.min_func_size, opt_levels=args.opt_levels)

    if args.merge_results:
        merge_results(
            args.merge_results, args.use_dec, args.use_metric, show_diffs=args.show_diffs, show_stats=args.show_stats,
            min_func_size=args.min_func_size, max_func_size=args.max_func_size
        )

    if args.summarize_targets:
        summarize_many_targets(
            args.summarize_targets, args.use_dec, args.use_metric, show_diffs=args.show_diffs, show_stats=args.show_stats,
            min_func_size=args.min_func_size, max_func_size=args.max_func_size, opt_levels=args.opt_levels
        )

    if args.archive_targets:
        archive_targets(args.archive_targets, opt_levels=args.opt_levels)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="""
    A helper script for running the three phases of SAILR evaluation: compiling, decompiling, and running
    the SAILR metrics (measuring). Each stage can be triggered individually or together. Each stage is run
    in it's own container which shares volumes.
    """)
    #
    # compile flags
    #
    parser.add_argument(
        '-c', '--compile', nargs='*', action="store", help="""
        Takes some or none args that must be names of targets in the target folder. These targets will be compiled
        using the locations specified in the toml. If no args are passed to the compile flag, but it is still used,
        all targets in the targets folder will be compiled.
        """
    )
    parser.add_argument(
        '--cflags', type=str, default=BASE_FLAGS, help=f"""
        The flags that should be passed to the compiler. If not specified, the default is {BASE_FLAGS}. Only useful
        with the compile option. 
        """
    )
    parser.add_argument(
        '--cc', type=str, default="gcc-9", help=f"""
        The compiler to use in C compilation
        """
    )
    parser.add_argument(
        '--cxx', type=str, default="g++-9", help=f"""
        The compiler to use in C++ compilation
        """
    )
    parser.add_argument(
        '--update-path', type=str, help=f"""
        Temporarily update the path 
        """
    )

    #
    # decompilation
    #
    parser.add_argument(
        '-d', '--decompile', nargs='*', action="store", help=f"""
        Takes some or none args that must be names of targets in the target folder. These targets will be decompiled
        using the locations specified in the toml, which will be relative to the ./results dir. If this
        is run without the compilation flag first, you need to populate the {SAILR_COMPILATION_RESULTS_DIR} dir found
        in the package dir. If no args are passed to the decompile flag, but it is still used, all targets in
        the targets folder with a valid compilation results dir will be decompiled. 
        """
    )
    parser.add_argument(
        '--use-dec', nargs='+', default=ALL_DECOMPILERS, choices=ALL_DECOMPILERS, help=f"""
        Takes a list of decompilers you want used, which should be from the following list: {ALL_DECOMPILERS}. If
        no decompilers are specified, then all supported decompilers will be run. 
        """
    )
    parser.add_argument(
        '--symboless', default=False, action="store_true", help=f"""
        Use this flag if you want all functions to be considered without symbols (addrs only)
        """
    )

    #
    # measure
    #
    parser.add_argument(
        '-m', '--measure', nargs='*', action="store"
    )
    parser.add_argument(
        '--use-metric', nargs="+", default=ALL_METRICS, choices=ALL_METRICS
    )
    parser.add_argument(
        '--min-func-size', type=int, default=None
    )
    parser.add_argument(
        '--max-func-size', type=int, default=None
    )
    parser.add_argument(
        '--show-diffs', default=False, action="store_true"
    )
    parser.add_argument(
        '--show-stats', default=False, action="store_true"
    )

    #
    # full-eval & all
    #

    parser.add_argument(
        '--full-eval', nargs='*', action="store"
    )
    parser.add_argument(
        '--functions', nargs="+"
    )
    parser.add_argument(
        '--cores', type=int, default=1
    )
    parser.add_argument(
        "--clean", default=False, action="store_true", help="""
        If present, it will destroy the previous results for that opertation. As an example, if set when using
        decompilation, all other decompilation will be deleted before starting operation
        """
    )
    parser.add_argument(
        "--opt-levels", default=DEFAULT_OPTIMIZATION_LEVELS, choices=OPTIMIZATION_LEVELS, nargs="+", help="""
        The optimization levels to use when compiling. This is also useful for measuring and decompiling, since
        results will be based on the optimization level that you activate.
        """
    )

    #
    # Utils
    #

    parser.add_argument(
        "--merge-results", nargs="+", help="""
        If present, it will merge all existing result toml files into a singular file containing
        all of the results along with a summary of said results.
        """
    )
    parser.add_argument(
        "--summarize-targets", nargs="+", help="""
        Summarizes many directory results that are all different packages!
        """
    )
    parser.add_argument(
        "--archive-targets", nargs="+", help="""
        Copies and moves old measurements and decompilation. Input is a SAILRTarget name. 
        """
    )

    args = parser.parse_args()
    if args.compile is None and args.decompile is None and args.measure is None and \
            args.merge_results is None and args.full_eval is None and args.merge_results:
        parser.print_help()
    main(args)
