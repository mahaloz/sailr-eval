# SAILR Evaluation Pipeline
The SAILR evaluation pipeline, `sailreval`, is a tool for measuring various aspects of decompilation quality.
This evaluation pipeline was originally developed for the USENIX 2024 paper ["Ahoy SAILR! There is No Need to DREAM of C:
A Compiler-Aware Structuring Algorithm for Binary Decompilation"](https://www.zionbasque.com/files/publications/sailr_usenix24.pdf). It supports 26 different C packages from Debian,
for compiling, decompiling, and measuring. Currently, angr, Hex-Rays (IDA Pro), and Ghidra are supported as decompilers.

If you are only looking to use the SAILR version of angr, then jump to the [using SAILR on angr](#using-sailr-on-angr-decompiler) section.

## Table of Contents
- [Overview](#overview)
- [Installation](#installation)
- [Usage](#usage)
  - [Compilation](#compiling)
  - [Decompilation](#decompiling)
  - [Measuring](#measuring)
  - [Aggregation](#aggregating)
- [SAILR Paper Artifacts](#sailr-paper-artifacts)
  - [Using SAILR on angr decompiler](#using-sailr-on-angr-decompiler)
  - [SAILR evaluation results files](#sailr-evaluation-results-files)
  - [Reproducing SAILR paper results](#reproducing-sailr-paper-results)
- [Miscellaneous](#miscellaneous)
  - [Compiling Windows Targets](#compiling-windows-targets)


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

Note: you will need to install the system dependencies for the Python project yourself, listed [here]([CI runner](./.github/workflows/python-app.yml).
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

## SAILR Paper Artifacts
The [SAILR paper](https://www.zionbasque.com/files/publications/sailr_usenix24.pdf) introduced four artifacts:
1. The [angr decompiler](https://github.com/angr/angr/tree/master/angr/analyses/decompiler), found in the [angr](https://github.com/angr/angr) repo. 
2. The [SAILR](https://github.com/mahaloz/angr-sailr/tree/sailr/angr/analyses/decompiler/optimization_passes) algorithm, 
built on the angr decompiler as optimization passes.
3. The SAILR evaluation pipeline, found in the `sailreval` Python package
4. The results of `sailreval` for the paper (tomls and decompilation outputs)

Below you will find instructions for using each of these artifacts.

### Using SAILR on angr decompiler
Currently, SAILR is being slowly [integrated into the angr master branch](https://github.com/angr/angr/issues/4229). 
Until then, you can use the [angr-sailr](https://github.com/mahaloz/angr-sailr/tree/be3855762a84983137696aa14efe2431a86a7e97) 
fork of angr inside our provided stripped down Dockerfile found in [misc/angr_sailr_dec/Dockerfile](./misc/angr_sailr_dec/Dockerfile).
You can also use the pre-built docker image found on [Dockerhub](https://hub.docker.com/r/mahaloz/angr-sailr-dec) (~3.5gb).
Note, this fork will not receive updates and is the exact version used in the paper. 
The commit is [be3855762a84983137696aa14efe2431a86a7e97](https://github.com/mahaloz/angr-sailr/tree/be3855762a84983137696aa14efe2431a86a7e97).

To build the decompiler docker image, run, from the root of the repo:
```bash
docker build -t angr-sailr-dec -f misc/angr_sailr_dec/Dockerfile .
```

You could now run the image with `docker run --rm -it angr-sailr-dec`, but we recommend using the wrapper script.
You can use the wrapper script that will run this image for you:
```bash
./scripts/docker-angr-sailr-dec.sh --help
```

**NOTE**: this mounts the current directory into the container so the decompiler can access the binary.


Verify your version works by running it on the `motivating_example` binary in the root of the repo:
```bash 
./scripts/docker-angr-sailr-dec.sh ./tests/binaries/motivating_example schedule_job --structuring-algo sailr
```

If working correctly, you should see the following output, which matches the papers example:
```c
long long schedule_job(unsigned long a0, unsigned long long a1, unsigned long a2) {
    if (a0 && a1) {
        complete_job();
        if (EARLY_EXIT == a2)
            goto LABEL_40126b;
        next_job();
    }
    refresh_jobs();
    if (a1 || a1)
        fast_unlock();
LABEL_40126b:
    complete_job();
    log_workers();
    return job_status(a1);
}
```

### SAILR evaluation results files
In the SAILR paper, we run an evaluation on all 26 packages in the [targets](./targets) directory.
We generated data for optimization levels `O0`, `O1`, `O2`, and `O3`. 
We also recorded the decompilation on all these targets with the following decompilers: 
`SAILR`, `IDA Pro 8.0`, `Ghidra 10.1`, `Phoenix`, `DREAM`, and `rev.ng`. In each `sailr_decompiled` folder,
you will find files likes so `<decompiler>_<binary_name>.c`. For example, `sailr_decompiled/ida_mv.c` is the decompilation
of `mv` from coreutils with IDA Pro 8.0. angr based decompilation starts with `angr_` and then the structuring algorithm.

All the files, which are about 11gbs in total, can be downloaded from [this Dropbox link](https://www.dropbox.com/scl/fi/ez5ra4yzxrynio7opxquo/results.tar.gz?rlkey=vi5ntdw48a9ohfnd0x8p32ael&dl=0).

After downloading, you can extract the files with:
```bash
tar xf results.tar.gz --use-compress-program=pigz
```

The will looks like the following (but with more files):
```tree
results/
├── O0
├── O1
├── O2
│   └── coreutils
│       ├── sailr_compiled
│       ├── sailr_decompiled
│       └── sailr_measured
└── O3
```

To further understand what is contained in the `sailr_*` folders, see the [usage](#usage) section above.
You can now use the `sailreval` package to aggregate the results like so to get the results from the paper:
```bash
./eval.py --summarize-targets ./eval.py --measure bash libselinux shadow libedit base-passwd openssh-portable \
          dpkg dash grep diffutils findutils gnutls iproute2 gzip sysvinit bzip2 libacl libexpat libbsd tar rsyslog \
          cronie zlib e2fsprogs coreutils \
          --use-dec source ida ghidra angr_sailr angr_phoenix angr_dream angr_comb \
          --use-metric gotos cfged bools func_calls \
          --opt-levels O0 O1 O2 O3 \
          --show-stats
```

### Reproducing SAILR paper results
We ran the entire pipeline of SAILR on an Ubuntu 22.04 machine that had 40 logical cores and 64 GB of RAM.
With these specs, it took about 8 hours to run the entire pipline for all 26 packages on the O2 optimization level.
If you intend to reproduce the results as they were in the paper, checkout this repo to commit [8442959e99c9d386c2cdfaf11346bf0f56e959eb](https://github.com/mahaloz/sailr-eval/commit/8442959e99c9d386c2cdfaf11346bf0f56e959eb), 
which was the last version with minor fixes to the pipeline, but not edits to CFGED. 
If you plan on evaluating modernly, use the latest commit, since it will have stability, speed, and other fixes to components of SAILR. 

Due to slowness in processing of source with Joern, we recommend running the Joern stage **LOCALLY** and not in the 
container. Here is an example run of only coreutils:
```bash
./docker-eval.sh --compile coreutils --cores 20 && \
./eval.py --decompile coreutils --use-dec source --cores 20 && \
./docker-eval.sh --decompile coreutils --use-dec ghidra angr_sailr angr_phoenix angr_dream angr_comb --cores 20 && \
./eval.py --measure coreutils --use-metric gotos cfged bools func_calls --use-dec source ghidra angr_sailr angr_phoenix angr_dream angr_comb --cores 20 && \
./eval.py --summarize-targets coreutils --use-dec source ghidra angr_sailr angr_phoenix angr_dream angr_comb --use-metric gotos cfged bools func_calls --show-stats
```
Take note of when `eval.py` is run instead of the docker version. 

To reproduce the results from the paper, you run the following evaluation scripts that will run the entire pipeline for you:
```bash
./scripts/evaluation/all_packages_o2_table3.sh
./scripts/evaluation/coreutils_o2_table4.sh
```

Run them one at a time to observe their output. 

Note, you will likely **not** get the exact numbers shown in the paper, but the final conclusions on the numbers (i.e. the relative distance of each score) should be the same.
This is due to a fundamental limitation in CFGED, which relies on GED to compute the edit distance between two CFGs.
Since we never know if GED will conclude, we must use a timeout, which can be affected by the machine you run on.
However, for most cases the timeout should not be triggered.

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

To run the full pipeline for Widnows targets, you must have [llvm-pdbutil](https://github.com/shaharv/llvm-pdbutil-builds)
installed on the system. 
