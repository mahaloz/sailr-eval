import os
import re
import sys

import angr
from sailreval.decompilers.angr_dec import angr_decompile

import unittest

BINARIES_PATH = os.path.join(os.path.dirname(os.path.realpath(__file__)), "./binaries/")


def decompile_function(binary_path, func_name):
    return angr_decompile(binary_path, functions=[func_name], print_dec=True)


def run_many(times):
    def _run_many(function):
        def __run_many(*args, **kwargs):
            for i in range(times):
                result = function(*args, **kwargs)
            return result
        return __run_many
    return _run_many


class TestDeduplicationReverter(unittest.TestCase):
    def test_test1(self):
        """
        Tests the simplest case of deduplication where only a single block is duplicated
        """
        decomp = decompile_function(os.path.join(BINARIES_PATH, "test1"), "foo")
        text: str = decomp

        self.assertEqual(text.count("first print"), 1)
        self.assertEqual(text.count("second print"), 1)
        self.assertEqual(text.count("third print"), 1)
        self.assertEqual(text.count("if"), 2)
        self.assertEqual(text.count("goto"), 0)

    def test_test2(self):
        """
        Tests the case of a multiple blocks being duplicated with overlapping conditions in an
        if-elif-else structure that causes some graph to be duplicated.
        """
        decomp = decompile_function(os.path.join(BINARIES_PATH, "test2"), "foo")
        text: str = decomp

        self.assertEqual(text.count("first print"), 1)
        self.assertLessEqual(text.count("second print"), 1)
        # TODO: thse should be 1, but we give up for now
        self.assertEqual(text.count("third print"), 2)
        self.assertEqual(text.count("fourth print"), 2)
        # TODO: still need to add more fixes to remove the redudant condition graph
        # this is the same problem at the end of test1
        """
        self.assertEqual(text.count("&&"), 2)
        self.assertEqual(text.count("||"), 1)
        self.assertEqual(text.count("if"), 3)
        """

    def _DISABLED_test_true_emit_ancillary_info(self):
        # TODO: this is disabled until we fix gettext having multiple args
        """
        Found in `true` binary, tests deduplication of an entire graph, with simple
        post blocks (no continuing graph)
        decomp = decompile_function(os.path.join(BINARIES_PATH, "coreutils/true.o"), "emit_ancillary_info.constprop.0")
        text: str = decomp.text

        self.assertEqual(text.count("\\n%s online help: <%s>\\n"), 1)
        self.assertEqual(text.count("Full documentation <%s%s>\\n"), 1)
        self.assertEqual(text.count("or available locally via: info '(coreutils) %s%s'\\n"), 1)
        self.assertEqual(text.count("Report any translation bugs to <https://translationproject.org/team/>\\n"), 1)
        """
        assert True

    def test_true_localcharset_get_charset_aliases(self):
        """
        Tests a complicated partial graph where some pre-blocks and post-blocks differ across
        the duplicated graph
        """
        func_addr = 0x404410
        decomp = decompile_function(os.path.join(BINARIES_PATH, "true_localcharset"), func_addr)
        text: str = decomp

        #
        # first fix:
        # removes the duplicated graphs that start with malloc and end in memcpy
        #
        assert text.count("malloc") == 2

        #
        # second fix:
        # removes the duplicated call
        # TODO: fix this, the goto that makes this de-duplication possible is removed right now
        #
        assert text.count("sub_404860") == 1


    def test_sort_zaptemp(self):
        decomp = decompile_function(os.path.join(BINARIES_PATH, "coreutils/sort.o"), "zaptemp")
        text: str = decomp

        self.assertNotIn("{\n}", decomp)
        self.assertEqual(text.count("goto"), 0)
        # If failing, check that the variable name has not changed. Gernerally, this is checking that
        # the last if-stmt exists with only a single variable in its conditions
        null_if_cases = re.findall(r"if \(!*\*\(v4\)\)", decomp)
        self.assertEqual(len(null_if_cases), 1)

    def test_cksum_digest_split_3(self):
        """
        This tests the deduplicator goto-trigger is not too sensitive. In this binary there is duplicate assignment
        that was legit written by the programmer. It so happens to be close to a goto, which used to trigger this opt
        to remove it and cause more gotos. Therefore, this should actually never result in a succesful fixup of the
        assignment.
        """

        decomp = decompile_function(os.path.join(BINARIES_PATH, "coreutils/cksum-digest.o"), "split_3")
        text: str = decomp

        # the `v9` may change, but the `algorithm_bits` should not
        good_assighment = "digest_length = *((&algorithm_bits + 0x4 * v9));"

        assert "{\n}" not in decomp
        assert text.count(good_assighment) == 2


class TestMaximizeSimilarity(unittest.TestCase):
    def test_nohup_main(self):
        """
        The blocks 0x400a75 and 0x400bd9, are closely similar, but are misaligned by 1 instruction that
        should happen before the call. This optimization makes sure that they get optimized to be the largest
        similar amount they can be.
        """
        decomp = decompile_function(os.path.join(BINARIES_PATH, "coreutils/nohup.o"), "main")
        text: str = decomp

        self.assertNotIn("{\n}", decomp)
        self.assertEqual(text.count("isatty(0x2)"), 1)
        self.assertLessEqual(text.count("goto"), 8)


class TestConstPropReverter(unittest.TestCase):
    def test_fmt_main(self):
        """
        This testcase tests 2 things:
        1. that block merger works
        2. that CallArgSimplifier works

        Since the target is a duplicated call where one of the params that was a regsiter
        gets replaced with a variable.

        To better understand why CallArgSimplifier is used see Zions notes for:
        2022-04-14
        2022-04-04
        """
        decomp = decompile_function(os.path.join(BINARIES_PATH, "coreutils/fmt.o"), "main")
        text: str = decomp

        self.assertEqual(text.count("invalid width"), 2)
        self.assertEqual(text.count("xdectoumax"), 2)


class TestReturnDuplicator(unittest.TestCase):
    def test_test_binop(self):
        decomp = decompile_function(os.path.join(BINARIES_PATH, "coreutils/test.o"), "binop")
        text: str = decomp
        
        self.assertNotIn("{\n}", decomp)
        self.assertEqual(text.count("goto"), 0)

    def test_tail_tail_bytes(self):
        decomp = decompile_function(os.path.join(BINARIES_PATH, "coreutils/tail.o"), "tail_bytes.constprop.0")
        text: str = decomp

        self.assertNotIn("{\n}", decomp)
        self.assertEqual(text.count("goto"), 0)

    def test_tsort_search_item(self):
        decomp = decompile_function(os.path.join(BINARIES_PATH, "coreutils/tsort.o"), "search_item")
        text: str = decomp

        # validate not empty output
        self.assertNotIn("{\n}", decomp)
        self.assertGreaterEqual(text.count("assert_fail"), 1)

        self.assertEqual(text.count("goto"), 0)

    def test_dd_iread(self):
        decomp = decompile_function(os.path.join(BINARIES_PATH, "coreutils/dd.o"), "iread")
        text: str = decomp

        # validate not empty output
        self.assertNotIn("{\n}", decomp)
        assert text.count("return") <= 4
        assert text.count("goto") == 0

    def test_stty_recover_mode(self):
        decomp = decompile_function(os.path.join(BINARIES_PATH, "coreutils/stty.o"), "recover_mode")
        text: str = decomp

        # validate not empty output
        self.assertNotIn("{\n}", decomp)
        assert text.count("return") <= 4
        assert text.count("goto") == 0

class TestLoweredSwitchReverter(unittest.TestCase):
    def DISABLED_test_cksum_digest_filename_unescape(self):
        """
        This is disabled because ReturnSimplifier will remove a goto that triggered this. 
        """
        decomp = decompile_function(os.path.join(BINARIES_PATH, "coreutils/cksum-digest.o"), "filename_unescape")
        text: str = decomp

        self.assertEqual(text.count("switch "), 1)
        self.assertEqual(text.count("case 92:"), 1)
        self.assertEqual(text.count("goto"), 1)


class TestCrossJumpReverter(unittest.TestCase):
    def test_chcon_process_file(self):
        decomp = decompile_function(os.path.join(BINARIES_PATH, "coreutils/chcon.o"), "process_file")
        text: str = decomp

        self.assertGreaterEqual(text.count("switch "), 1)
        self.assertLessEqual(text.count("goto"), 1)


if __name__ == "__main__":
    unittest.main(argv=sys.argv)
