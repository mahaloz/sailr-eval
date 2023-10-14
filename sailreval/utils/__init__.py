import shutil
from pathlib import Path
import os
import logging
import signal

import toml

l = logging.getLogger(__name__)

#
# Consts
#

SAILR_COMPILATION_RESULTS_DIR = "sailr_compiled"
SAILR_DECOMPILATION_RESULTS_DIR = "sailr_decompiled"
SAILR_MEASURE_RESULTS_DIR = "sailr_measured"

#
# printing colors
#

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


#
# filesystem helpers
#

class WorkDirContext:
    def __init__(self, path: Path):
        self.path = path
        self.origin = Path(os.getcwd()).absolute()

    def __enter__(self):
        os.chdir(self.path)

    def __exit__(self, exc_type, exc_val, exc_tb):
        os.chdir(self.origin)


def force_mkdir(path: Path):
    path = Path(path).expanduser().absolute()
    if path.exists():
        shutil.rmtree(path, ignore_errors=True)

    try:
        os.mkdir(path)
    except Exception as e:
        l.warning(f"Failed to make directory because {e}")


class timeout:
    def __init__(self, seconds=1, error_message='Timeout'):
        self.seconds = seconds
        self.error_message = error_message

    def handle_timeout(self, signum, frame):
        raise TimeoutError(self.error_message)

    def __enter__(self):
        signal.signal(signal.SIGALRM, self.handle_timeout)
        signal.alarm(self.seconds)

    def __exit__(self, type_, value, traceback):
        signal.alarm(0)


def load_tomls_by_bin_name(dir_path: Path):
    exclusion_names = {"summary.toml", "results.toml"}
    dir_path = Path(dir_path).absolute()
    data_by_bin_name = {}

    for file_path in dir_path.glob("*.toml"):
        if file_path.name in exclusion_names:
            continue

        with open(file_path.absolute(), "r") as fp:
            data = toml.load(fp)

        # XXX: this changes if you change the format
        exclusion_keys = ["binary", "total_time", "timeout"]
        bin_name = data.get("binary", None)

        if bin_name is None:
            continue

        # remove non-data
        for k in exclusion_keys:
            if k in data:
                del data[k]

        data_by_bin_name[bin_name] = data

    return data_by_bin_name
