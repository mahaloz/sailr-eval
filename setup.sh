#!/bin/bash

[ "$(uname)" == "Darwin" ] && IS_MACOS=1 || IS_MACOS=0

# create results output directories for each optimization level in SAILR Pipeline
echo "Creating results directories for pipeline runs (failure ok)..."
mkdir results
mkdir results/O0
mkdir results/O1
mkdir results/O2
mkdir results/O3

# install graphviz locally
echo "Installing graphviz for sailreval package..."
if [ $EUID -eq 0 ]
then
    export SUDO=
else
    export SUDO=sudo
fi
if [ -e /etc/debian_version ]
then
    $SUDO apt-get install -y graphviz-dev openjdk-19-jdk unzip
elif [ $IS_MACOS -eq 1 ]
then
    if ! which brew > /dev/null;
    then
        error "You must have homebrew installed for MacOS installs."
    fi
    brew install graphviz-dev openjdk@19 unzip
else
    error "System is unknown, please install graphviz-dev on your system!"
fi

echo "Installing the sailreval Python package locally..."
pip3 install -e . && pyjoern --install

# build docker image
echo "Building docker image (~6gb)..."
docker build . -t sailr-eval
