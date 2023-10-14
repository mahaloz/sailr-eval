# pylint: disable=missing-class-docstring
import platform
import urllib.request
from pathlib import Path
import sys
from distutils.util import get_platform
from distutils.command.build import build as st_build
from subprocess import run

from setuptools import setup
from setuptools.command.develop import develop as st_develop


def _download_joern_zipfile(save_location: Path) -> Path:
    url = "https://github.com/joernio/joern/releases/download/v1.2.18/joern-cli.zip"
    with urllib.request.urlopen(url) as response:
        if response.status != 200:
            raise Exception(f"HTTP error {response.status}: {response.reason}")

        with open(save_location, 'wb') as f:
            while True:
                chunk = response.read(8192)
                if not chunk:
                    break
                f.write(chunk)

    return save_location


def _download_joern():
    joern_bin_dir = Path("sailreval/joern/bin/").absolute()
    joern_binary = joern_bin_dir / "joern"
    if joern_binary.exists():
        return

    # download joern
    joern_zip_file = _download_joern_zipfile(joern_bin_dir / "joern-cli.zip")
    # unzip joern
    run(["unzip", str(joern_zip_file)], cwd=str(joern_bin_dir))
    # remove zip file
    joern_zip_file.unlink()


class build(st_build):
    def run(self, *args):
        self.execute(_download_joern, (), msg="Downloading Joern from GitHub...")
        super().run(*args)


class develop(st_develop):
    def run(self, *args):
        self.execute(_download_joern, (), msg="Downloading Joern from GitHub...")
        super().run(*args)


cmdclass = {
    "build": build,
    "develop": develop,
}

if 'bdist_wheel' in sys.argv and '--plat-name' not in sys.argv:
    sys.argv.append('--plat-name')
    name = get_platform()
    if 'linux' in name:
        sys.argv.append('manylinux2014_' + platform.machine())
    else:
        # https://www.python.org/dev/peps/pep-0425/
        sys.argv.append(name.replace('.', '_').replace('-', '_'))

setup(cmdclass=cmdclass)
