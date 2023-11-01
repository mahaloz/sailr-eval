import unittest
from pathlib import Path
import subprocess
import os

import toml

from sailreval import SAILR_DECOMPILERS, SAILR_METRICS

TESTS_DIR = Path(__file__).parent.absolute()
SCRIPTS_DIR = (TESTS_DIR.parent / "scripts").absolute()


def undockerify_script(script_path: Path, output_path: Path) -> Path:
    with open(script_path, "r") as f:
        script = f.read()

    script = script.replace("sudo ./docker-eval.sh", "./eval.py")
    with open(output_path, "w") as f:
        f.write(script)

    os.chmod(str(output_path), os.stat(str(output_path)).st_mode | 0o111)
    return output_path


class TestPipeline(unittest.TestCase):
    def test_eval_script(self):
        """
        Tests every stage in the eval.py script as described in the README.
        """
        opt_level = "O2"
        project = "example_project"
        decompilers = [SAILR_DECOMPILERS.SOURCE_CODE, SAILR_DECOMPILERS.ANGR_SAILR, SAILR_DECOMPILERS.ANGR_DREAM]
        metrics = [SAILR_METRICS.GOTO_COUNT, SAILR_METRICS.BOOLEAN_COUNT, SAILR_METRICS.FUNC_CALLS, SAILR_METRICS.CFGED]

        # take the verification script and replace docker instances (for CI run)
        eval_script_copy = undockerify_script(SCRIPTS_DIR / "verify_pipeline.sh", TESTS_DIR / "verify_pipeline.sh")
        # run the eval script like normal uses would run it (without docker)
        ret = subprocess.run([f"{eval_script_copy}"], shell=True, cwd=TESTS_DIR)
        assert ret.returncode == 0

        # verify the output
        results_file = Path("results.toml")
        assert results_file.exists()
        with open(results_file, "r") as f:
            results = toml.load(f)

        project_results = results[f"{opt_level}/{project}"]
        for dec in decompilers:
            assert dec in project_results
            for metric in metrics:
                # since we are requesting --show-stats in eval, we need to check for the sum instead of normal
                # metric name; normally, this suffix is not needed.
                assert f"{metric}_sum" in project_results[dec]

        # make sure real numbers occurred
        assert project_results[SAILR_DECOMPILERS.SOURCE_CODE][f"{SAILR_METRICS.GOTO_COUNT}_sum"] == 1
        for dec in decompilers:
            assert project_results[dec][f"{SAILR_METRICS.FUNC_CALLS}_sum"] > 0

        # verify we had the same number of functions as in source (8)
        metadata = project_results["metadata"]
        assert metadata["total_unique_functions_in_src"] == 8
        assert metadata["total_unique_functions_in_all_metrics"] == 8

        # cleanup:
        eval_script_copy.unlink()
        results_file.unlink()
        Path("full_summary.md").unlink()
        Path("summary.md").unlink()
