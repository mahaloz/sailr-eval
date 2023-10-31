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
from cfgutils.similarity import graph_edit_distance_core_analysis, ged_upperbound

FILES_PATH = Path(os.path.join(os.path.dirname(os.path.realpath(__file__)), "./cfged/"))
DECOMPILERS = {
    SAILR_DECOMPILERS.SOURCE_CODE: None,
    SAILR_DECOMPILERS.ANGR_SAILR: angr_decompile,
    SAILR_DECOMPILERS.IDA: ida_decompile
}


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


class TestCFGED(unittest.TestCase):
    def test_dump_linemaps(self):
        # test dwarf dumping
        binary_path = FILES_PATH / "cat/cat.o"
        out = dump_dwarf_addr_to_line_map(binary_path)
        self.assertTrue(out.exists())

        # test angr dumping
        out = angr_decompile(binary_path, dump_line_maps=True)
        self.assertTrue(out.with_suffix(".linemaps").exists())
    
    def test_cfged_is_ged(self):
        binary_path = FILES_PATH/"cat.o"
        filename = binary_path.with_suffix("").name
        decompilers = (SAILR_DECOMPILERS.IDA, SAILR_DECOMPILERS.ANGR_SAILR)
        functions = ["next_line_num", "usage"]
        angr_decompile_and_get_dwarf_info(binary_path, functions=functions)
        for function in functions:
            src_cfg = extract_cfgs_for_decompiler(binary_path.parent, filename, "source", function=function)
            for dec in decompilers:
                dec_cfg = extract_cfgs_for_decompiler(binary_path.parent, filename, dec, function=function)
                cfged_score = compute_cfg_edit_distance(dec_cfg, src_cfg, function, binary_path, dec)
                exact_score = graph_edit_distance_core_analysis(dec_cfg, src_cfg, with_timeout=120)
                print(f"Decompiler: {dec}, Function: {function}, CFGED: {cfged_score}, GED: {exact_score}")
                self.assertEqual(cfged_score, exact_score)

                # special case for IDA
                if dec == SAILR_DECOMPILERS.IDA and function == "next_line_num":
                    self.assertEqual(exact_score, 0)
        cleanup_angr_and_src_files(binary_path, filename)

    def test_cfged_on_large_functions(self):
        """
        Tests that CFGED is less than or equal to the upper bound GED computed on large functions. In this case,
        we use the cat binary which contains at least one large function greater than 80 blocks large.
        We also test the fmt binary.
        """
        targets = {
            "cat": ['cat'],
            "fmt": ['get_paragraph'],
        }
        for target, functions in targets.items():
            binary_path = FILES_PATH/f"{target}.o"
            filename = binary_path.with_suffix("").name
            decompilers = (SAILR_DECOMPILERS.IDA, SAILR_DECOMPILERS.ANGR_SAILR)
            angr_decompile_and_get_dwarf_info(binary_path, functions=functions)
            for function in functions:
                src_cfg = extract_cfgs_for_decompiler(binary_path.parent, filename, "source", function=function)
                for dec in decompilers:
                    dec_cfg = extract_cfgs_for_decompiler(binary_path.parent, filename, dec, function=function)
                    cfged_score = compute_cfg_edit_distance(dec_cfg, src_cfg, function, binary_path, dec)
                    approx_score = ged_upperbound(dec_cfg, src_cfg)
                    print(f"Decompiler: {dec}, Function: {function}, CFGED: {cfged_score}, Upper-GED: {approx_score}")
                    # must be within 10% if it is larger
                    self.assertLessEqual(cfged_score, approx_score*1.10)

            cleanup_angr_and_src_files(binary_path, filename)


if __name__ == "__main__":
    unittest.main(argv=sys.argv)
