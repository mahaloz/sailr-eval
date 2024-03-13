import os
import time
from multiprocessing.pool import Pool
from pathlib import Path
from subprocess import run
import shutil
import logging
import re
from typing import Dict
import traceback

import toml
from tqdm import tqdm

from .sailr_target import SAILRTarget
from ..utils import timeout
from . import (
    bcolors, WorkDirContext, SAILR_COMPILATION_RESULTS_DIR, SAILR_DECOMPILATION_RESULTS_DIR,
    SAILR_MEASURE_RESULTS_DIR
)
from .. import SAILR_METRICS

l = logging.getLogger(__name__)

#
# compile flags
#

DEFAULT_OPTIMIZATION_LEVELS = ["O2"]
OPTIMIZATION_LEVELS = ["O0", "O1", "O2", "O3"]

# old debug flags
DUMP_GED_SOURCE = "-fno-inline -fdump-tree-original"
DUMP_FLAGS = "-fdump-tree-all-details -fdump-rtl-all"

# base flag, always start with this
BASE_FLAGS = f"-g -fno-inline -fno-builtin -save-temps=obj"
# Jump Threading
NO_JUMP_THREAD = "-fno-thread-jumps -fno-tree-vrp -fno-branch-target-load-optimize -fno-branch-target-load-optimize2 " \
                 "-fno-tree-dominator-opts -fdisable-tree-ethread -fdisable-tree-thread1 -fdisable-tree-thread2 " \
                 "-fdisable-tree-thread3 -fdisable-tree-thread4"
# Common Subexpression Elimination (run the 3 below together as one)
NO_CSE = "-fno-cse-skip-blocks -fno-cse-follow-jumps -fno-rerun-cse-after-loop -fdisable-rtl-cse1 -fdisable-rtl-cse2"
NO_GCSE = "-fno-gcse -fno-gcse-lm -fdisable-rtl-gcse2"
NO_PRE = "-fno-tree-pre"  # partial redundancy elimination (a type of CSE)

# Switch Conversion
NO_SWITCH_CONV = "-fno-tree-switch-conversion -fno-tree-tail-merge"

# Cross Jumping
NO_CROSS_JUMPING = "-fno-crossjumping -fdisable-rtl-jump -fdisable-rtl-jump2"

# Software-Thread Cache Basic Block Reordering
NO_STC_BBRO = "-freorder-blocks-algorithm=simple -fno-reorder-blocks"

# Loop Header & Invariant Optimizations
NO_LOOP_HEADER = "-fno-tree-ch"
NO_LOOP_INV = "-fno-tree-loop-optimize -fdisable-rtl-loop2_invariant"

# Forward Store Motion
NO_TREE_SINK = "-fno-tree-sink"

# No Builtins (a type of inlining)
NO_BUILTIN = "-fno-builtin"

# DISABLE EVERYTHING!
NO_EVERYTHING = f"{BASE_FLAGS} {DUMP_FLAGS} {NO_JUMP_THREAD} {NO_CSE} {NO_GCSE} {NO_PRE} {NO_SWITCH_CONV} {NO_CROSS_JUMPING} {NO_STC_BBRO} {NO_LOOP_HEADER} {NO_LOOP_INV} {NO_TREE_SINK}"

# Then do:
# - No Switch Functions
# - No Gotos from Source
# - No IDA failures

PKG_COPY_BLACKLIST = {"kmod",} 

def sailr_target_src_exists(sailr_target: SAILRTarget, opt_level="O2") -> bool:
    results_dir = Path(f"./results/{opt_level}/").absolute()
    package_dir = results_dir.joinpath(sailr_target.package_dir).absolute()
    return package_dir.exists() 


def compile_and_copy_clean_files(sailr_target: SAILRTarget, cflags, cores, opt_levels=DEFAULT_OPTIMIZATION_LEVELS,  cc='gcc', cxx='g++', clean=False):
    # if any targets are not existent, check to see if we can copy files over
    if sailr_target.download and not all(sailr_target_src_exists(sailr_target, opt_level=lvl) for lvl in opt_levels):
        l.info("Detecting some optimization levels need files for compiling. Checking other levels...")

        if sailr_target.package_name not in PKG_COPY_BLACKLIST:
            # find an already downloaded target, do caching
            for cached_opt_level in opt_levels:
                if sailr_target_src_exists(sailr_target, opt_level=cached_opt_level):
                    break
            else:
                # if none exists then we download one
                cached_opt_level = opt_levels[0]
                setup_sailr_compile_target(sailr_target, cached_opt_level)

            for opt_level in opt_levels:
                if opt_level == cached_opt_level:
                    continue
                
                # copy files over for each target
                l.info(f"Copying files from {cached_opt_level} to {opt_level}...")
                copy_compiled_files_from_opt(sailr_target, cached_opt_level, opt_level)
        else:
            # blacklist packages require all files to be setup :( 
            for opt_level in opt_levels:
                setup_sailr_compile_target(sailr_target, opt_level)

    # compile the actual files now
    for opt_level in opt_levels:
        compile_target(
            sailr_target, cflags, cores, opt_level, cc=cc, cxx=cxx, 
            setup_target=not sailr_target_src_exists(sailr_target, opt_level=opt_level)
        )
        if sailr_target.skip_file_copy:
            continue

        compiled_res_dir = copy_compiled_files(sailr_target, opt_level)
        if compiled_res_dir is None:
            continue


def clean_and_update_source_from_i(compiled_res_dir, sailr_target: SAILRTarget, save_linemaps=True):
    """
    Only works with *.i files are in the directory given, otherwise no work is done.

    :param compiled_res_dir:
    :param save_linemaps:
    :return:
    """
    l.info("Cleaning and mapping source lines now. This may take a minute...")
    cleaned_files_ln_map = clean_target_i_files(compiled_res_dir, sailr_target)
    if save_linemaps:
        if not cleaned_files_ln_map:
            l.info("There are no files to clean...")
            return
        correct_and_save_line_maps(cleaned_files_ln_map)


def _collect_function_lines(
    src_file, i_file, known_linemap, joern_port=9000,
    metrics=[SAILR_METRICS.GOTO_COUNT, SAILR_METRICS.BOOLEAN_COUNT, SAILR_METRICS.FUNC_CALLS],
    do_tiemout=True,
):
    from ..analysis.measure import measure
    metric_amount = len(metrics) if metrics else 0
    cachable_results = {}
    basename = i_file.with_suffix("").with_suffix("").name

    from pyjoern import JoernClient, JoernServer

    def _eval_with_server(joern_port, src_file, i_file):
        with JoernServer(port=joern_port):
            src_client = JoernClient(src_file, port=joern_port)
            src_ln_map = src_client.function_line_numbers()
            src_functions = src_client.functions

        if not src_functions:
            raise ValueError(f"Could not find any functions in {src_file}")

        with JoernServer(port=joern_port + 1):
            client = JoernClient(i_file, port=joern_port + 1, bin_name=basename)
            i_ln_map = client.function_line_numbers()
            extra_metrics = {SAILR_METRICS.DEC_TIME: 0.0}
            cache_res = measure(i_file, basename, metrics, src_functions, client=client, **extra_metrics)

        return cache_res, src_functions, i_ln_map, src_ln_map

    try:
        if do_tiemout:
            with timeout(seconds=100 + 20 * metric_amount):
                cachable_results[basename], src_functions, i_ln_map, src_ln_map = _eval_with_server(joern_port, src_file, i_file)
        else:
            cachable_results[basename], src_functions, i_ln_map, src_ln_map = _eval_with_server(joern_port, src_file, i_file)
    except (TimeoutError, Exception) as e:
        l.info(f"JOERN timeout for {src_file}! with {e}")
        traceback.print_exception(e)
        return None, None, None, None

    final_linemap = {}
    for function, (src_start, src_end) in src_ln_map.items():
        func_linemap = {}
        i_data = i_ln_map.get(function, None)
        if i_data is None:
            continue

        i_start, i_end = i_data
        src_pos = src_start
        for ln in range(i_start, i_end+1):
            # skip if known
            if ln in known_linemap:
                func_linemap[ln] = known_linemap[ln]
                continue

            func_linemap[ln] = src_pos
            src_pos += 1

        final_linemap[function] = func_linemap

    str_linemaps = {}
    for func, mapping in final_linemap.items():
        str_linemaps[func] = {str(k): v for k,v in mapping.items()}

    name = i_file.with_suffix("").with_suffix("").name
    out_file = i_file.parent.joinpath(f"source_{name}.linemaps")
    with open(out_file, "w") as fp:
        toml.dump(str_linemaps, fp)

    with open(i_file.parent.joinpath(f"source_{name}.toml"), "w") as fp:
        toml.dump(cachable_results[basename], fp)

    return i_file, i_ln_map, known_linemap, src_ln_map


def correct_and_save_line_maps(cleaned_files_lines_map: Dict, cores=15, joern_port_start=9000):
    # 1. get line start and end for every function, by name, in each file (*.c and *.i)
    pairs = []
    for cleaned_file, line_map in cleaned_files_lines_map.items():
        src_path = cleaned_file.with_suffix("").with_suffix(".c")
        alt_src_path = cleaned_file.with_suffix("").with_suffix(".orig.c")
        is_alt = False
        if not src_path.exists():
            is_alt = True
            if not alt_src_path.exists():
                continue
            src_path = alt_src_path

        if not is_alt:
            # move .c -> .orig.c (for parsing)
            shutil.move(src_path, src_path.with_suffix(".orig.c"))

        # copy .i.c -> .c (for later pipeline)
        shutil.copy(cleaned_file, src_path)

        if not is_alt:
            src_path = src_path.with_suffix(".orig.c")
        pairs.append((src_path, cleaned_file, line_map))

    linemaps = {}
    with Pool(processes=cores) as pool, tqdm(total=len(pairs)) as pbar:
        work = []
        for i, pair in enumerate(pairs):
            work.append(pool.apply_async(
                _collect_function_lines,
                args=(pair[0], pair[1], pair[2]),
                kwds={"joern_port": joern_port_start+2*i},
                callback=lambda _: pbar.update(1)
            ))

        pool.close()
        for w in work:
            try:
                out = w.get(timeout=200)
                if not out:
                    pbar.update(1)
                    continue

                if len(out) < 4:
                    pbar.update(1)
                    continue

                f, i_ln_map, known_linemap, src_ln_map = out
                if f is None:
                    pbar.update(1)
                    continue

                linemaps[f] = (i_ln_map, known_linemap, src_ln_map)
            except Exception as e:
                print(e)
                pbar.update(1)
                continue

    # 2. We now have all the lines. Starting at each function traverse start to finish, ignoring places we already
    # know from the known_linemap
    linemap_by_file = {}
    for filepath, (i_ln_map, known_linemap, src_ln_map) in linemaps.items():
        final_linemap = {}
        for function, (src_start, src_end) in src_ln_map.items():
            func_linemap = {}
            i_data = i_ln_map.get(function, None)
            if i_data is None:
                continue

            i_start, i_end = i_data
            src_pos = src_start
            for ln in range(i_start, i_end+1):
                # skip if known
                if ln in known_linemap:
                    func_linemap[ln] = known_linemap[ln]
                    continue

                func_linemap[ln] = src_pos
                src_pos += 1

            final_linemap[function] = func_linemap

        linemap_by_file[filepath] = final_linemap

    if not linemap_by_file:
        l.critical("Nonexistent linemaps for all files!")

    # 3. save all the linemaps
    for i_c_filepath, linemap in linemap_by_file.items():
        str_linemaps = {}
        for func, mapping in linemap.items():
            str_linemaps[func] = {str(k): v for k,v in mapping.items()}

        name = i_c_filepath.with_suffix("").with_suffix("").name
        out_file = i_c_filepath.parent.joinpath(f"source_{name}.linemaps")
        with open(out_file, "w") as fp:
            toml.dump(str_linemaps, fp)

    return linemap_by_file


def clean_target_i_files(compiled_results_dir: Path, sailr_target: SAILRTarget):
    files = list(compiled_results_dir.rglob("*.i"))
    cleaned_file_ln_map = {}
    for file in files:
        new_file, ln_map = clean_i_file(file.absolute(), sailr_target)
        cleaned_file_ln_map[new_file] = ln_map

    return cleaned_file_ln_map


def clean_i_file(filepath: Path, sailr_target: SAILRTarget):
    filepath = Path(filepath)
    if sailr_target and sailr_target.windows_project:
        line_comment_str = b'#line ([0-9]+) \"(.+)\".*'
    else:
        line_comment_str = b'# ([0-9]+) \"(.+)\".*'

    with open(filepath, "rb") as fp:
        data = fp.read()

    data = re.sub(b"__extension__ extern [^;]*;\n", b"", data, flags=re.DOTALL)
    data = re.sub(b"extern [^;]*;\n", b"", data, flags=re.DOTALL)
    data = re.sub(b"__extension__\n", b"", data, flags=re.DOTALL)
    lines = data.split(b"\n")
    clean_lines = list()
    for i in range(1, len(lines)):
        prev_line = lines[i-1]
        curr_line = lines[i]

        # skip curr line with debug
        has_debug = re.match(b"#.*", curr_line)
        if has_debug is not None and curr_line.startswith(b"#"):
            continue

        prev_has_debug = re.match(line_comment_str, prev_line)
        line_num = None
        if prev_has_debug is not None and prev_line.startswith(b"#") and Path(prev_has_debug[2].decode()).with_suffix("").name == filepath.with_suffix("").name:
            line_num = int(prev_has_debug[1])

        clean_lines.append((curr_line, line_num))

    # reconstruct the data
    data = b""
    corrected_linenumbers = {}
    for i, (line, linenum) in enumerate(clean_lines):
        data += line + b"\n"
        if linenum is not None:
            corrected_linenumbers[i] = linenum

    #
    # removes special comments found in GCC preprocessing:
    # https://gcc.gnu.org/onlinedocs/cpp/Preprocessor-Output.html
    #
    #data = re.sub(b"#.*\n", b"", data)
    #data = re.sub(b"\\[\\[.*\\]\\]", b"", data)

    with open(filepath, "wb") as fp:
        fp.write(data)

    #
    # make the output look decent with clang-format
    #
    #run(f"clang-format -i {filepath}".split())

    new_file = filepath.with_suffix(".i.c")
    shutil.move(filepath, new_file)

    return new_file, corrected_linenumbers


def copy_compiled_files(sailr_target: SAILRTarget, opt_level):
    target_dir = Path(f"./results/{opt_level}/").joinpath(sailr_target.package_dir).absolute()
    if not target_dir.exists():
        l.warning(f"Was unable to find the package directory for {sailr_target.package_name}")
        return None

    target_src_dir = target_dir.joinpath(sailr_target.source_dir).absolute()
    if not target_src_dir.exists():
        l.warning(f"was unable to find the source directory for package {sailr_target.package_name} for {sailr_target.source_dir}")
        return None

    # make compilation output dir if it does not exist
    sailr_comp_dir = target_dir.joinpath(SAILR_COMPILATION_RESULTS_DIR).absolute()
    if sailr_comp_dir.exists():
        shutil.rmtree(sailr_comp_dir, ignore_errors=True)
    os.mkdir(sailr_comp_dir)

    # copy .i, .c, and .o files
    file_ends = (".i", ".c", ".o")
    for file_end in file_ends:
        files = list(target_src_dir.rglob(f"*{file_end}"))
        for file in files:
            new_loc = sailr_comp_dir.joinpath(file.name).absolute()
            if sailr_target.rename_dash_files:
                if "-" in new_loc.name:
                    new_loc = new_loc.with_name("-".join(new_loc.name.split("-")[1:]))

            if new_loc.exists():
                l.warning(f"Overwriting a file {file.name} that already exists")

            shutil.copy(file.absolute(), new_loc)

    # remove files without all 3!
    bad_files = set()
    for file_end in file_ends:
        other_ends = [end for end in file_ends if end != file_end]
        for file in list(sailr_comp_dir.rglob(f"*{file_end}")):
            if not file.with_suffix(other_ends[0]).exists() or not file.with_suffix(other_ends[1]).exists():
                bad_files.add(file.absolute())

    for file in bad_files:
        l.warning(f"Removing {file} because it is missing other files")
        os.unlink(file)

    good_files = sorted(list(sailr_comp_dir.rglob(f"*.o")))
    if sailr_target.subset_compilation:
        bad_files = good_files[sailr_target.subset_compilation:]
        for file in bad_files:
            os.unlink(file)
            os.unlink(file.with_suffix(".i"))
            os.unlink(file.with_suffix(".c"))

    return sailr_comp_dir


def copy_compiled_files_from_opt(sailr_target: SAILRTarget, src_opt_level, dst_opt_level):
    src_dir = Path(f"./results/{src_opt_level}/").joinpath(sailr_target.package_dir).absolute()
    dst_dir = Path(f"./results/{dst_opt_level}/").joinpath(sailr_target.package_dir).absolute()
    l.info(f"Using cached download to copy files from {src_dir} to {dst_dir}")
    shutil.copytree(src_dir, dst_dir, ignore_dangling_symlinks=True)


def setup_sailr_compile_target(sailr_target: SAILRTarget, opt_level):
    l.info(f"Downloading files for {sailr_target.package_name}/{opt_level}...")
    if opt_level not in OPTIMIZATION_LEVELS:
        l.critical(f"Invalid optimization level {opt_level}, quiting...")
        return

    results_dir = Path(f"./results/{opt_level}/").absolute()
    # download and unpack the target if download is on for the target
    if sailr_target.download:
        with WorkDirContext(results_dir):
            package_dir_top = ""
            if sailr_target.package_dir:
                package_dir_top = Path(sailr_target.package_dir)
                # only use the parent if you see subdirs in the package folder
                if "/" in sailr_target.package_dir:
                    package_dir_top = package_dir_top.parent

            filename = sailr_target.source_remote.split("/")[-1]
            if sailr_target.remote_type.lower() == "git":
                run(f"git clone {sailr_target.source_remote} {package_dir_top}".split())
            elif sailr_target.remote_type.lower() == "zip":
                run(f"wget -nc {sailr_target.source_remote}".split())
                run(f"unzip -o {filename}".split())
                run(f"rm {filename}".split())
            elif sailr_target.remote_type.lower() == "tar":
                run(f"wget -nc {sailr_target.source_remote}".split())
                run(f"tar xvf {filename}".split())
                run(f"rm {filename}".split())
            elif sailr_target.remote_type.lower() == "local":
                local_folder = Path(sailr_target.source_remote).absolute()
                shutil.copytree(local_folder, sailr_target.package_dir, ignore_dangling_symlinks=True)
            else:
                print(f"unsupported or missing remote file type: {sailr_target.remote_type}, {sailr_target.source_remote}")

    # now we are inside the package
    with WorkDirContext(results_dir.joinpath(sailr_target.package_dir)):
        # if download was run in this execution, we must attempt a checkout
        # if the remote type is git; we may also need to do post-download things
        if sailr_target.download:
            # checkout to the correct git version
            if sailr_target.version and sailr_target.remote_type.lower() == "git":
                run(f"git fetch --tags".split())
                run(f"git checkout tags/{sailr_target.version} -b sailr_eval".split())

            # run post-download commands
            if sailr_target.post_download_cmds:
                for cmd in sailr_target.post_download_cmds:
                    run(cmd.split())

            # apply patch if it has one
            if sailr_target.apply_patch:
                patch_path = results_dir.joinpath("patches").joinpath(sailr_target.apply_patch).absolute()
                if patch_path.exists():
                    run(f"git apply {patch_path}".split())


def compile_target(sailr_target: SAILRTarget, cflags, cores, opt_level, cc='gcc', cxx='g++', setup_target=True):
    if sailr_target.skip_compilation:
        l.warning("This project is marked to skip automated compilation. Skipping...")
        return

    if sailr_target.windows_project:
        l.warning("Windows projects must be compiled manually. Assuming files are in this dir and copying them...")
        return

    if setup_target:
        setup_sailr_compile_target(sailr_target, opt_level)

    results_dir = Path(f"./results/{opt_level}/").absolute()
    with WorkDirContext(results_dir.joinpath(sailr_target.package_dir)):
        # start setting up the environment for compiling
        # make a copy of the current env so we can edit it later
        d = dict(os.environ)
        d['CC'] = sailr_target.c_compiler or cc
        d['CXX'] = sailr_target.cpp_compiler or cxx
        d['CFLAGS'] = f"-{opt_level} " + cflags
        d['CPPFLAGS'] = d['CFLAGS']

        print(f"{bcolors.WARNING}{bcolors.BOLD} Configuring with flags: {bcolors.ENDC} {d['CFLAGS']} for {d['CC']}")
        time.sleep(1)

        if sailr_target.pre_make_cmds:
            for cmd in sailr_target.pre_make_cmds:
                print(f"running {cmd}")
                ret = run(cmd.split(), env=d)
                # verify things were configured!
                if ret.returncode != 0:
                    print("Failed to configure... please check the log file file config.log")

        print(f"{bcolors.WARNING}{bcolors.BOLD} Configuration successful, compiling now... {bcolors.ENDC} {d['CFLAGS']}")
        time.sleep(1)

        run(f"make clean".split(), env=d)
        if sailr_target.override_make_vars:
            base_make_cmd = sailr_target.make_cmd.split()
            new_make_cmd = base_make_cmd[:1] + [f'CFLAGS={cflags}'] + base_make_cmd[1:]
            new_make_cmd += [f'-j{cores}'] if cores != 1 else []
            run(new_make_cmd, env=d)
        else:
            run(f"{sailr_target.make_cmd} {'-j'+str(cores) if cores != 1 else ''}".split(), env=d)

        if sailr_target.post_make_cmds:
            run(sailr_target.post_make_cmds.split())


def strip_file(filepath: Path):
    run(f"strip --strip-debug {filepath}".split())
