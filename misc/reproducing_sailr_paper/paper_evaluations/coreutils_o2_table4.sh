#!/bin/bash

# compile all coreutils
./docker-eval.sh --compile coreutils_gcc5 coreutils coreutils_gcc11 coreutils_clang14 --cores 60 --opt-levels O2 && \
# decompile (preprocess) only the source first
./eval.py --decompile coreutils_gcc5 coreutils coreutils_gcc11 coreutils_clang14 --use-dec source --cores 20 \
  --opt-levels O2 && \
# decompile with all supported decompilers
./docker-eval.sh --compile coreutils_gcc5 coreutils coreutils_gcc11 coreutils_clang14 --cores 60 --opt-levels O2 \
  --use-dec angr_sailr ghidra angr_phoenix angr_dream angr_comb && \
# measure the decompilation results
./eval.py --measure coreutils_gcc5 coreutils coreutils_gcc11 coreutils_clang14 --cores 50 --opt-levels O2 \
  --use-dec source angr_sailr ghidra angr_phoenix angr_dream angr_comb \
  --use-metric gotos bools func_calls cfged && \
# pretty print them out
./eval.py --merge-results ./results/O2/coreutils*/sailr_measured/ --opt-levels O2 \
  --use-dec source angr_sailr ghidra angr_phoenix angr_dream angr_comb \
  --use-metric gotos bools func_calls cfged
