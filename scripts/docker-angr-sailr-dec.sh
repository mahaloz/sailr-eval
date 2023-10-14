#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Erorr: usage: $0 <binary_path> <function> <args>"
  exit 1
fi

# grab the first argument
BINARY_PATH=$1
# prepend /host/ to the path
BINARY_PATH="/host/$BINARY_PATH"

docker run \
  -it \
  --rm \
  -v $PWD:/host \
  angr-sailr-dec \
  $BINARY_PATH \
  "${@:2}"