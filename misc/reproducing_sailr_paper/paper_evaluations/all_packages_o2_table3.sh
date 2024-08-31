#!/bin/bash

# compile all 26 packages
./docker-eval.sh --compile libselinux shadow libedit base-passwd openssh-portable dpkg dash grep kmod \
  diffutils findutils gnutls iproute2 gzip sysvinit bzip2 libacl libexpat libbsd tar rsyslog cronie zlib e2fsprogs \
  coreutils --cores 70 --opt-levels O2 --cc gcc-9 --cxx g++-9 && \
# decompile (preprocess) only the source first
./eval.py --decompile libselinux shadow libedit base-passwd openssh-portable dpkg dash grep kmod \
  diffutils findutils gnutls iproute2 gzip sysvinit bzip2 libacl libexpat libbsd tar rsyslog cronie zlib e2fsprogs \
  coreutils --cores 20 --opt-levels O2 --use-dec source && \
# decompile with all supported decompilers
./docker-eval.py --decompile libselinux shadow libedit base-passwd openssh-portable dpkg dash grep kmod \
  diffutils findutils gnutls iproute2 gzip sysvinit bzip2 libacl libexpat libbsd tar rsyslog cronie zlib e2fsprogs \
  coreutils --cores 70 --opt-levels O2 \
  --use-dec source angr_sailr ida ghidra angr_phoenix angr_dream angr_comb && \
# measure the decompilation results
./docker-eval.py --measure libselinux shadow libedit base-passwd openssh-portable dpkg dash grep kmod \
  diffutils findutils gnutls iproute2 gzip sysvinit bzip2 libacl libexpat libbsd tar rsyslog cronie zlib e2fsprogs \
  coreutils --cores 50 --opt-levels O2 \
  --use-dec source angr_sailr ida ghidra angr_phoenix angr_dream angr_comb \
  --use-metric gotos bools func_calls cfged && \
# pretty print them out
./eval.py --summarize-targets libselinux shadow libedit base-passwd openssh-portable dpkg dash grep kmod \
  diffutils findutils gnutls iproute2 gzip sysvinit bzip2 libacl libexpat libbsd tar rsyslog cronie zlib e2fsprogs \
  coreutils --opt-levels O2 \
  --use-dec source angr_sailr ida ghidra angr_phoenix angr_dream angr_comb \
  --use-metric gotos bools func_calls cfged
