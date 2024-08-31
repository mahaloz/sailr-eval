# SAILR Evaluation Pipeline

<p align="center">
   <img src="https://i.imgur.com/VUnGRHU.png" style="width: 30%;" alt="angr-sailr Logo"/>
</p>

The SAILR evaluation pipeline, `sailreval`, is a tool for measuring various aspects of decompilation quality.
This evaluation pipeline was originally developed for the USENIX 2024 paper ["Ahoy SAILR! There is No Need to DREAM of C:
A Compiler-Aware Structuring Algorithm for Binary Decompilation"](https://www.zionbasque.com/files/publications/sailr_usenix24.pdf). It supports 26 different C packages from Debian,
for compiling, decompiling, and measuring. Currently, angr, Hex-Rays (IDA Pro), and Ghidra are supported as decompilers.

If you are only looking to use the SAILR version of angr, simply use angr! The latest version of angr now uses SAILR!
If you are looking to reproduce the exact results of the SAILR paper, then jump to [this README](./misc/reproducing_sailr_paper/README.md) for a submission version. 

## Table of Contents
- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
  - [Compilation](#compiling)
  - [Decompilation](#decompiling)
  - [Measuring](#measuring)
  - [Aggregation](#aggregating)
- [Example Run](#example-run)
- [Miscellaneous](#miscellaneous)
  - [Compiling Windows Targets](#compiling-windows-targets)
- [Citation](#citation)


## Overview:
This repo contains the `sailreval` Python package and information about the SAILR paper artifacts.
`sailreval` is the Python package that contains all the code for running the evaluation pipeline.
`sailreval` evaluates the quality of decompilation by comparing it to the original source code.
This evaluation is done in four phases:
1. [Compilation](#compilation): a project described in the [targets](./targets) directory is downloaded, preprocessed, and compiled into object files.
2. [Decompilation](#decompilation): decompilers [supported in sailreval](./sailreval/decompilers) are used to decompile the object files into C source files.
3. [Measurement](#measuring): the preprocessed source and decompiled source are compared using [metrics](./sailreval/metrics) in `sailreval`.
4. [Aggregation](#aggregating): the results from the measurement are normalized for functions that had a metric on all decompilers.

Each phase requires the phase directly before it runs; however, you can skip stages if you manually provide the
required files. For example, you can skip the decompilation phase if you already have the object files and preprocessed source.

## Installation
The `sailreval` package can be used in two ways: locally or in a docker container.
If you plan on reproducing the results of the SAILR paper or using some pre-packaged decompiler like Ghidra, then you
will need both. Below are two methods for installing: one is heavy (docker and local), and one is light (only local).
Make sure you have Docker installed on your system. 

### Install Script (Recommended)
On Linux and MacOS:
```bash
./setup.sh
```

This will build the Docker container, install system dependencies, and install the Python package locally.

### Only Python Package
If you want to use only local decompilers and you have the build dependencies installed for your compiled project, you
can install the Python package without the Docker container. For an example of this use case, see 
our [CI runner](./.github/workflows/python-app.yml).
```bash
pip3 insatll -e .
```

Note: you will need to install the system dependencies for the Python project yourself, listed [here](./.github/workflows/python-app.yml).
The package is also available on PyPi, so remote installation works as well. 

### Install Verification
Verify the installation by running:
```bash
./scripts/verify_pipeline.sh
```

This will use both the Docker container and your local install to run the Pipeline. 
If you installed it correctly, you should see some final output like:
```md
# Evaluation Data
## Stats
Layout: ('sum', 'mean', 'median')
### O2
Metric     | source      | angr_sailr  | angr_dream
---------- | ----------- | ----------- | -----------
gotos      | 1/0.12/0.0  | 1/0.12/0.0     | 0/0/0.0
...
```

## Usage
After installation, if you used the script normally (i.e. the docker install), than you can use the `docker-eval.sh` script
which is a proxy to the `eval.py` script, but inside the container. 
As an example you can use:
```bash
./docker-eval.sh --help
./eval.py --help
```

They should both produce the same result.

Using the steps below, you can run the entire pipeline stage-by-stage. In each evaluated target in `targets` you will
be able to find a `sailr_compiled`, `sailr_decompiled`, and `sailr_measured` folder in the package folder. 
Each folder will contain the results of the respective stage. All targets are places in the `results` directory under
their respective optimization. 
For coreutils compiled with O2, you'll see `results/O2/coreutils`.

### Compiling
To compile a package it must be described in the `targets` folder by a `target.toml`. Here is coreutils:
```toml
package_name = "coreutils"
source_remote = "git://git.sv.gnu.org/coreutils.git"
remote_type = "git"
download = true
post_download_cmds = ["./bootstrap"]
version = "v9.1"
package_dir = "coreutils"
pre_make_cmds = ["./configure --quiet"]
make_cmd = "make"
post_make_cmds = []
source_dir = "src"
```

There are many flags that you can set which are defined in the [sailr_target](./sailreval/utils/sailr_target.py) class.

We compile just coreutils using the docker wrapper:
```sh 
docker-eval.sh --compile coreutils --cores 8 --opt-levels O2
```

After compiling is done, you can find the results in the `results/O2/coreutils` directory. 
In the `sailr_compiled` folder located in `coreutils` you will find all the object files, preprocessed source, and normal source.
The next phase will destroy the normal source and replace it with the preprocessed source. 
It's critical that you do not edit the preprocessed source in any way.

### Decompiling
The target must contain the `sailr_compiled` folder with `.o` files in it. In the case of coreutils that would be:
`./results/O2/coreutils/sailr_compiled/`. The source must also be present in that folder. 

For the very first time you decompile a target, you must "decompile" the source, which creates normalized preprocessed source.
Do it like so:
```
./eval.py --decompile coreutils --use-dec source --cores 20 --opt-levels O2
```

Highly recommend to run locally for speed. 
After this is done, you don't need to do it again even if you re-decompile for other decompilers.

Next, you decompile all the decompilers you want:
```
./docker-eval.sh --decompile coreutils --use-dec ghidra angr_sailr angr_phoenix --cores 20 --opt-levels O2
```

All the decompilation files, including the preprocessed source, will be found inside the `sailr_decompiled` folder.
For coreutils that would be: `./results/O2/coreutils/sailr_decompiled/`.
You will find the preprocessed source as `source_*.c` and the decompilation as `<decompiler>_*.c`.
You will also notice files like `angr_sailr_mv.linemaps`, `angr_sailr_mv.toml`, and `mv.dwarf.linemaps`.
These files contain the line mappings for decompiled source to original source and pre-computed metrics like `goto` counts.

If you plan on using IDA Pro, you must mount it into the container. 
Please mount the `idat64` binary directly into the container at `/tools/`.
To do that, add `-v /path/to/idat64_folder/:/tools/` to the `docker run` command in the [docker-eval.sh](./scripts/docker-eval.sh) script.


### Measuring
Like the decompilation phase, this phase requires the `sailr_decompiled` to exist with `.o` and `.c` files in it.
If you plan on using `cfged`, then the `sailr_decompild` folder must contain the linemaps, toml, and dwarf files for each targeted object file.

If you ran the decompilation step above, you should automatically have that. Measure with: 
```sh 
./eval.py --measure coreutils --use-metric gotos cfged --use-dec source angr_sailr --cores 15
```
**NOTE**: you must put `source` as one of the targeted decompilers if you are using `cfged`. 

After runing, you will find files in the `sailr_measured` folder. 
For coreutils that would be: `./results/O2/coreutils/sailr_measured/`.
In the folder you will find various `toml` files that look like the following:

```toml
binary = "mv"
total_time = 231.44658088684082
timeout = false

[source.cfged]
main = "0.0"

[source.gotos]
main = 0 

[angr_sailr.cfged]
main = "309.0"

[angr_sailr.gotos]
main = 11
# ...
```

You can use the `toml` library in Python to load these files into a dictionary.
The dictionary is keyed by `[decompiler][metric][function]` and the value is the metric value.

### Aggregating

After measuring, you can aggregate the results like so:
```sh
./eval.py --summarize-targets coreutils --use-dec source angr_sailr --use-metric gotos cfged 
```

The results will look something like, which is all sums:
```markdown
# Evaluation Data
## Stats

### O2
Decompiler | gotos_sum | cfged_sum
---------- | --------- | ---------
source     | 46        | 0
angr_sailr | 668       | 39701


## Metadata

total_unique_functions_in_src | total_unique_functions_in_all_metrics
----------------------------- | -------------------------------------
1152                          | 918
```

Only the last printed table matters. Tables printed before that are intermediate results.
You can also show `Sum/Average/Median` by using the `--show-stats` arg. 

The above summarization is the normalized results where each count is based on functions that successfully decompiled and measured
on all decompilers specified in the command. You can also do multiple targets at once:
```sh
./eval.py --summarize-targets coreutils diffutils ...
```

There is a special case summarization for projects that are the same but may have different names.
This happens in the case of `coreutils` and `coreutils_gcc5`. Both are Coreutils compiled with different decompilers.
You can normalize across both projects for binaries and functions that only exist across both projects with:
```sh
./eval.py --merge-results ./results/O2/coreutils*/sailr_measured --use-dec source angr_sailr --use-metric gotos cfged
```

## Example Run
Here is an example run of the pipeline:
```sh
./docker-eval.sh --compile coreutils --cores 20 && \
./eval.py --decompile coreutils --use-dec source --cores 20 && \
./docker-eval.sh --decompile coreutils --use-dec ghidra angr_sailr angr_phoenix angr_dream angr_comb --cores 20 && \
./eval.py --measure coreutils --use-metric gotos cfged bools func_calls --use-dec source ghidra angr_sailr angr_phoenix angr_dream angr_comb --cores 20 && \
./eval.py --summarize-targets coreutils --use-dec source ghidra angr_sailr angr_phoenix angr_dream angr_comb --use-metric gotos cfged bools func_calls --show-stats
```


## Miscellaneous
### Compiling Windows Targets
Windows targets, like `libz_windows`, will not be compiled by this pipeline, so you must compile them yourself. 
Follow the following the steps to compile a windows target:
1. Download the source code for the target specified in the targets toml file
2. Make a new configuration in MSVC `Project->Properties->Configuration Manager->Active Solution Configuration->New`
3. Name is `SAILR`
4. Go to `Project->Properties->C/C++->Preprocessor` and enable Preprocessor Definitions to File 
5. Hit compile with SAILR config, the copy all `*.i`, `*.c`, and `*.obj` files into the `src` folder you need to make
6. Rename the `*.obj` to `*.o`
7. If step `5` failed, then just remove the preprocessor option after running once

To run the full pipeline for Windows targets, you must have [llvm-pdbutil](https://github.com/shaharv/llvm-pdbutil-builds)
installed on the system. 

## Citation
If you use this tool in your research, please cite out paper:
```bib
@inproceedings{basque2024ahoy,
  title={Ahoy sailr! there is no need to dream of c: A compiler-aware structuring algorithm for binary decompilation},
  author={Basque, Zion Leonahenahe and Bajaj, Ati Priya and Gibbs, Wil and O’Kain, Jude and Miao, Derron and Bao, Tiffany and Doup{\'e}, Adam and Shoshitaishvili, Yan and Wang, Ruoyu},
  booktitle={Proceedings of the USENIX Security Symposium},
  year={2024}
}
```