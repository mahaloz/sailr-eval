#!/bin/bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
PROJECT_DIR="$SCRIPT_DIR/.."
EXAMPLE_PROJECT_DIR="$SCRIPT_DIR/../tests/example_project"
RESULTS_DIR="$SCRIPT_DIR/../results/O2"
CORES="$(nproc --all)"

echo "Installing dependencies..."
sudo apt-get update && sudo apt-get install -y gcc make strip

echo "[+] Checking if results directory exists..."
if [ ! -d "$RESULTS_DIR" ]; then
    echo "[+] Creating results directory..."
    mkdir -p "$RESULTS_DIR"
fi

echo "[+] Running pipeline in $PROJECT_DIR..."
cd "$PROJECT_DIR" || exit 1

echo "[+] Running compilation pipeline..." && \
# runs on the default opts, which is O2
./eval.py --compile example_project --cores "$CORES" && \
echo "[+] Running decompilation pipeline (only for source)..." && \
./eval.py --decompile example_project --cores "$CORES" --use-dec source && \
echo "[+] Copying decompilation..." && \
mkdir -p "$PROJECT_DIR"/results/O2/example_project/sailr_decompiled && \
cp "$PROJECT_DIR"/tests/ci/angr* "$PROJECT_DIR"/results/O2/example_project/sailr_decompiled && \
echo "[+] Running measurement pipeline (gotos, bools, calls, cfged)..." && \
./eval.py --measure example_project --use-metric gotos cfged bools func_calls --use-dec source angr_sailr angr_dream --cores "$CORES" && \
echo "[+] Running aggregation pipeline..." && \
./eval.py --summarize-targets example_project --use-dec source angr_sailr angr_dream --use-metric gotos cfged bools func_calls --show-stats && \
# cleanup
rm -rf "$RESULTS_DIR/example_project" && \
echo "[+] The pipeline has successfully finished!" || (echo "[!] Pipeline failed, check the last stage it was in to figure out where!" && exit 1)
