import os
import sys
import shutil
from typing import List, Dict, Tuple

from .angr_dec import angr_decompile, angr_disassemble, get_all_funcs, angr_phoenix_decompile, angr_dream_decompile, \
    angr_improved_phoenix_decompile, angr_comb_decompile
from .ida_dec import ida_decompile
from .ghidra_dec import ghidra_decompile
from .. import ALL_DECOMPILERS, SAILR_DECOMPILERS
from ..utils import SAILR_DECOMPILATION_RESULTS_DIR, SAILR_COMPILATION_RESULTS_DIR, timeout
from ..utils.sailr_target import SAILRTarget
from ..utils.binary_debug_info import dump_dwarf_addr_to_line_map, dump_pdb_addr_to_line_map
from ..utils.compile import strip_file
from pathlib import Path
from multiprocessing import Pool
from multiprocessing.pool import ApplyResult
from tqdm import tqdm
import logging


l = logging.getLogger(__name__)


def _get_source(source_path, functions=None):
    return source_path


def _get_expanded_source(source_path, functions=None):
    source_path = Path(source_path).absolute()
    source_path = source_path.with_suffix(".i")
    return source_path


def get_decompile_func(dec_name):
    decompilers = {
        "source": _get_source,
        "expanded_source": _get_expanded_source,
        "angr_sailr": angr_decompile,
        "angr_improved_phoenix": angr_improved_phoenix_decompile,
        "angr_comb": angr_comb_decompile,
        "angr_phoenix": angr_phoenix_decompile,
        "angr_dream": angr_dream_decompile,
        "ghidra": ghidra_decompile,
        "ida": ida_decompile
    }

    return decompilers[dec_name]


def _copy_source_file_to_bin(binary_path, source_path, decompiler, copy_linemaps=True, sailr_target: SAILRTarget = None):
    source_path = Path(source_path)
    binary_name = binary_path.with_suffix("").name

    if decompiler == SAILR_DECOMPILERS.SOURCE_EXPANDED_CODE:
        source_path = source_path.with_suffix(".i").absolute()

    out_path = binary_path.parent.joinpath(f"{decompiler}_{binary_name}.c").absolute()
    shutil.copy(source_path, out_path)

    if copy_linemaps:
        # cached results from earlier stuff
        cache_path = source_path.parent.joinpath(f"{decompiler}_{binary_name}.toml")
        if cache_path.exists():
            shutil.copy(cache_path, out_path.parent)

        linemap_path = source_path.parent.joinpath(f"{decompiler}_{binary_name}.linemaps")
        if linemap_path.exists():
            shutil.copy(linemap_path, out_path.parent)
        
        # change the binary path for dumping dwarf, since it will be striped in the sailr decompiled folder
        non_stripped_binary_path = source_path.parent.joinpath(binary_path.name)
        if sailr_target is not None and sailr_target.windows_project:
            l.info(f"Windows project detected, dumping PDB line maps...")
            out = dump_pdb_addr_to_line_map(non_stripped_binary_path)
        else:
            out = dump_dwarf_addr_to_line_map(non_stripped_binary_path)
        shutil.move(out.absolute(), binary_path.parent)

    return out_path


def _decompile(decompiler, binary_path, functions, source_path=None, sailr_target: SAILRTarget = None, symboless=False):
    binary_path = Path(binary_path).absolute()
    if decompiler in (SAILR_DECOMPILERS.SOURCE_CODE, SAILR_DECOMPILERS.SOURCE_EXPANDED_CODE) and source_path:
        if source_path.exists():
            try:
                with timeout(seconds=100):
                    _copy_source_file_to_bin(binary_path, source_path, decompiler, sailr_target=sailr_target)
            except TimeoutError:
                l.info(f"Timout on DWARF collection for {binary_path}")
        return

    dec_func = get_decompile_func(decompiler)
    try:
        output_file = dec_func(binary_path, functions=functions, symboless=symboless)
    except Exception as e:
        l.critical(f"Failed to decompile {binary_path} with {decompiler} because {e}")
        return

    output_path = Path(os.getcwd()).joinpath(output_file)

    new_out_file = binary_path.parent.joinpath(output_path.name).absolute()
    shutil.move(output_path, new_out_file)

    # check for debug info
    if output_path.with_suffix(".linemaps").exists():
        shutil.move(output_path.with_suffix(".linemaps"), new_out_file.with_suffix(".linemaps"))

    # check for pre-metrics
    if output_path.with_suffix(".toml").exists():
        shutil.move(output_path.with_suffix(".toml"), new_out_file.with_suffix(".toml"))

    l.debug(f"Saving file to {new_out_file}")
    return new_out_file


def decompile_file(filepath, sailr_target=None, src_dir=None, functions=None, decompilers=None, cores=1, symboless=False):
    filepath = Path(filepath).absolute()
    source_path = Path(src_dir).joinpath(filepath.with_suffix("").name).with_suffix(".c").absolute() if src_dir else None

    # fill functions only if the decompiler NEEDS it. It's expensive to get all functions (uses angr).
    # this should always skip for only source
    uneeded_decs = {SAILR_DECOMPILERS.SOURCE_CODE, SAILR_DECOMPILERS.GHIDRA, SAILR_DECOMPILERS.IDA}
    if not functions and any([dec not in uneeded_decs for dec in decompilers]):
        functions = get_all_funcs(filepath)

    decompilers = decompilers or ALL_DECOMPILERS
    if not cores or cores == 1:
        # single core it
        for dec in decompilers:
            _decompile(dec, filepath, functions, source_path=source_path, sailr_target=sailr_target, symboless=symboless)
    else:
        # multi-core it
        pool = Pool(processes=len(decompilers))
        pool_results = {}
        for dec in decompilers:
            pool_results[dec] = pool.apply_async(
                _decompile,
                args=(dec, filepath, functions),
                kwds={"sailr_target": sailr_target, "source_path": source_path, "symboless": symboless},
            )
        pool.close()
        pool.join()
        for dec, res in pool_results.items():
            res.get()


#
# Batch functions for speeedup
#

def _prep_and_copy_target(target_package_dir: Path, target: SAILRTarget, clean=False):
    target_package_dir = Path(target_package_dir).absolute()

    # find SAILR compiled object files
    sailr_compile_dir = target_package_dir.joinpath(SAILR_COMPILATION_RESULTS_DIR).absolute()
    if not sailr_compile_dir.exists() and not target.skip_file_copy:
        l.error(f"SAILR Compile dir does not exist at {sailr_compile_dir}")
        return

    # clean and make SAILR decompiled output location
    sailr_decomp_dir = target_package_dir.joinpath(SAILR_DECOMPILATION_RESULTS_DIR).absolute()
    if clean and sailr_decomp_dir.exists():
        shutil.rmtree(sailr_decomp_dir)
        os.mkdir(sailr_decomp_dir)
    elif not sailr_decomp_dir.exists():
        os.mkdir(sailr_decomp_dir)

    # copy all compiled files to decompiled location
    obj_files = sailr_compile_dir.rglob("*.o")
    for obj_file in obj_files:
        shutil.copy(obj_file.absolute(), sailr_decomp_dir)
        new_file = sailr_decomp_dir.joinpath(obj_file.name)
        if not target.windows_project:
            strip_file(new_file)

    obj_file_compile_map = {
        p.expanduser().absolute(): (sailr_compile_dir.absolute(), target) for p in list(Path(sailr_decomp_dir).absolute().rglob("*.o"))
    }
    return obj_file_compile_map


def batch_decompile_and_move_obj_files(target_package_dirs: List[Tuple[Path, SAILRTarget]], decompilers=None, cores=1, clean=False, symboless=False):
    l.info(f"Starting batch decompilation of {len(target_package_dirs)} target directories...")
    # get the mapping for each object file and the source location it should go!
    obj_file_compile_map = {}
    for target_package_dir, target in target_package_dirs:
        obj_file_compile_map.update(_prep_and_copy_target(target_package_dir, target, clean=clean))

    batch_decompile_obj_files(obj_file_compile_map, decompilers=decompilers, cores=cores, symboless=symboless)


def batch_decompile_obj_files(obj_file_compile_map: Dict, decompilers=None, cores=1, symboless=False):
    if not cores or cores == 1:
        for obj_file_path, obj_items in obj_file_compile_map.items():
            obj_src_path, target = obj_items
            decompile_file(obj_file_path, sailr_target=target, decompilers=decompilers, src_dir=obj_src_path, symboless=symboless)
    else:
        with Pool(processes=cores) as pool, tqdm(total=len(obj_file_compile_map), file=sys.stdout) as pbar:
            work = {}
            for obj_file_path, obj_items in obj_file_compile_map.items():
                obj_src_path, target = obj_items
                w = pool.apply_async(
                    decompile_file,
                    args=(obj_file_path,),
                    kwds={"sailr_target": target, "decompilers": decompilers, "src_dir": obj_src_path, "symboless": symboless},
                    callback=lambda _: pbar.update(1)
                )
                job_args = (decompile_file, {"args": obj_file_path, "kwds": {"decompilers": decompilers, "src_dir": obj_src_path}})
                work[w] = job_args

            pool.close()
            for w, job_args in work.items():
                try:
                    w.get(timeout=600)
                except Exception as e:
                    l.critical(f"Job {job_args} failed with exception {e}")
                    pbar.update(1) 
                    continue
