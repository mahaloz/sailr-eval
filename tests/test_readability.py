from pathlib import Path
import sys
import os

from sailreval.utils.binary_debug_info import read_line_maps, gen_dwarf_addr_to_line_map, dump_dwarf_addr_to_line_map
from sailreval.metrics.ged_to_source import compute_cfg_edit_distance
from sailreval.decompilers.angr_dec import angr_decompile
from sailreval.decompilers.ida_dec import ida_decompile
from sailreval import SAILR_DECOMPILERS

import unittest
from pyjoern import fast_cfgs_from_source
from pyjoern.mapping import correct_source_cfg_addrs


FILES_PATH = Path(os.path.join(os.path.dirname(os.path.realpath(__file__)), "./cfged/"))
DECOMPILERS = {
    SAILR_DECOMPILERS.SOURCE_CODE: None,
    SAILR_DECOMPILERS.ANGR_SAILR: angr_decompile,
    SAILR_DECOMPILERS.IDA: ida_decompile
}

#
# helper functions
#


def extract_cfgs_for_decompiler(source_dir: Path, binary_name, decompiler, function=None):
    source_dir = Path(source_dir).absolute()
    out = fast_cfgs_from_source(source_dir.joinpath(f"{decompiler}_{binary_name}.c"))

    if decompiler == SAILR_DECOMPILERS.SOURCE_CODE:
        linemaps = source_dir.joinpath(f"source_{binary_name}.linemaps")
        out = correct_source_cfg_addrs(out, linemaps)

    return out[function] if function else out


def angr_decompile_and_get_dwarf_info(binary_path: Path, functions=None):
    angr_decompile(binary_path, functions=functions, print_dec=False, dump_line_maps=True)
    dump_dwarf_addr_to_line_map(binary_path)


def cleanup_angr_and_src_files(binary_path: Path, binary_name: str):
    binary_path = Path(binary_path).absolute()
    binary_path.parent.joinpath(f"angr_sailr_{binary_name}.linemaps").unlink()
    binary_path.parent.joinpath(f"angr_sailr_{binary_name}.c").unlink()
    binary_path.parent.joinpath(f"{binary_name}.dwarf.linemaps").unlink()


def angr_dec_cfged_score(binary_path: Path, functions=None):
    filename = binary_path.with_suffix("").name
    decompiler = SAILR_DECOMPILERS.ANGR_SAILR
    angr_decompile_and_get_dwarf_info(binary_path, functions=functions)
    scores = {}
    for function in functions:
        src_cfg = extract_cfgs_for_decompiler(binary_path.parent, filename, "source", function=function)
        dec_cfg = extract_cfgs_for_decompiler(binary_path.parent, filename, decompiler, function=function)
        cfged_score = compute_cfg_edit_distance(dec_cfg, src_cfg, function, binary_path, decompiler)
        scores[function] = cfged_score

    cleanup_angr_and_src_files(binary_path, filename)
    return scores

#
# tests
#


class TestReadability(unittest.TestCase):
    def test_shred_dosync(self):
        cfged_scores = angr_dec_cfged_score(FILES_PATH / "shred.o", functions=["dosync"])
        self.assertEqual(cfged_scores["dosync"], 0)

    def test_tsort_record_relation(self):
        cfged_scores = angr_dec_cfged_score(FILES_PATH / "tsort.o", functions=["record_relation"])
        self.assertEqual(cfged_scores["record_relation"], 0)

    def test_ptx_sort_found_occurs(self):
        cfged_scores = angr_dec_cfged_score(FILES_PATH / "ptx.o", functions=["sort_found_occurs"])
        self.assertEqual(cfged_scores["sort_found_occurs"], 0)


if __name__ == "__main__":
    unittest.main(argv=sys.argv)
