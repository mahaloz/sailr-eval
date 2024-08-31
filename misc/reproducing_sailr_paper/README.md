# SAILR Paper Artifacts
## Background
This README provides instructions for using and reproducing the results of the SAILR paper.
This will give you instructions on how to use the old **submission version of angr with SAILR**.
However, if you are looking to evaluate against SAILR, we highly recommend using the latest version of angr.

The [SAILR paper](https://www.zionbasque.com/files/publications/sailr_usenix24.pdf) introduced four artifacts:
1. The [angr decompiler](https://github.com/angr/angr/tree/master/angr/analyses/decompiler), found in the [angr](https://github.com/angr/angr) repo.
2. The [SAILR](https://github.com/angr/angr/tree/master/angr/analyses/decompiler/optimization_passes) algorithm,
   built on the angr decompiler as optimization passes (described more in [#14](https://github.com/mahaloz/sailr-eval/issues/14)).
3. The SAILR evaluation pipeline, found in the `sailreval` Python package
4. The results of `sailreval` for the paper (tomls and decompilation outputs)

Below you will find instructions for using each of these artifacts.

## Using SAILR on angr decompiler
SAILR is currently [in the latest version of angr](https://github.com/angr/angr/issues/4229), which includes bug fixes
and improvements over the version used in the paper.
However, if you would like the submission version, you can use the [angr-sailr](https://github.com/mahaloz/angr-sailr/tree/be3855762a84983137696aa14efe2431a86a7e97)
fork of angr inside our provided stripped down Dockerfile found in [angr_sailr_dec/Dockerfile](./angr_sailr_dec/Dockerfile).
You can also use the pre-built docker image found on [Dockerhub](https://hub.docker.com/r/mahaloz/angr-sailr-dec) (~3.5gb).
Note, this fork will not receive updates and is the exact version used in the paper.
The commit is [be3855762a84983137696aa14efe2431a86a7e97](https://github.com/mahaloz/angr-sailr/tree/be3855762a84983137696aa14efe2431a86a7e97).

To build the decompiler docker image, run, from the root of the repo:
```bash
docker build -t angr-sailr-dec -f ./angr_sailr_dec/Dockerfile .
```

You could now run the image with `docker run --rm -it angr-sailr-dec`, but we recommend using the wrapper script.
You can use the wrapper script that will run this image for you:
```bash
./docker-angr-sailr-dec.sh --help
```

**NOTE**: this mounts the current directory into the container so the decompiler can access the binary.


Verify your version works by running it on the `motivating_example` binary in the root of the repo:
```bash 
./docker-angr-sailr-dec.sh ./tests/binaries/motivating_example schedule_job --structuring-algo sailr
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

## SAILR evaluation results files
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
These commands assume you are in the root of the repo.
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

## Reproducing SAILR paper results
We ran the entire pipeline of SAILR on an Ubuntu 22.04 machine that had 40 logical cores and 64 GB of RAM.
With these specs, it took about 8 hours to run the entire pipline for all 26 packages on the O2 optimization level.
If you intend to reproduce the results as they were in the paper, checkout this repo to commit [8442959e99c9d386c2cdfaf11346bf0f56e959eb](https://github.com/mahaloz/sailr-eval/commit/8442959e99c9d386c2cdfaf11346bf0f56e959eb),
which was the last version with minor fixes to the pipeline, but not edits to CFGED.
If you plan on evaluating modernly, use the latest commit, since it will have stability, speed, and other fixes to components of SAILR.

Due to slowness in processing of source with Joern, we recommend running the Joern stage **LOCALLY** and not in the
container. These commands assume you are in the root of the repo. Here is an example run of only coreutils:
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
./paper_evaluations/all_packages_o2_table3.sh
./paper_evaluations/coreutils_o2_table4.sh
```

Run them one at a time to observe their output.

Note, you will likely **not** get the exact numbers shown in the paper, but the final conclusions on the numbers (i.e. the relative distance of each score) should be the same.
This is due to a fundamental limitation in CFGED, which relies on GED to compute the edit distance between two CFGs.
Since we never know if GED will conclude, we must use a timeout, which can be affected by the machine you run on.
However, for most cases the timeout should not be triggered.
