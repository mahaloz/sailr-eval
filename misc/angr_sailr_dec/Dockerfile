FROM --platform=linux/amd64 ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive

# install angr-dev required packages
RUN dpkg --add-architecture i386
RUN apt-get update && apt-get -o APT::Immediate-Configure=0 install -y \
        virtualenvwrapper python3-dev python3-pip build-essential libxml2-dev \
        libxslt1-dev git libffi-dev cmake libreadline-dev libtool debootstrap \
        debian-archive-keyring libglib2.0-dev libpixman-1-dev qtdeclarative5-dev \
        binutils-multiarch nasm libc6:i386 libgcc1:i386 libstdc++6:i386 \
        libtinfo5:i386 zlib1g:i386 libssl-dev \
        python-is-python3 graphviz-dev \
    && rm -rf /var/lib/apt/lists/* \
    && mkdir SAILR && mkdir versioned_tools

# install sailreval for the decompiler configuration in angr
COPY ./sailreval /SAILR/sailreval
COPY ./*.py /SAILR/
COPY ./scripts /SAILR/scripts
RUN pip3 install -e ./SAILR

WORKDIR versioned_tools

# ===========================================================
# angr decompiler (SAILR version)
# ===========================================================

# install angr, and all angr-packages, from the repos (for checkout ability)
ENV REPOS "archinfo pyvex cle claripy ailment angr"
RUN git clone https://github.com/angr/angr-dev.git && ( \
    cd ./angr-dev && \
    printf "I know this is a bad idea.\n" | ./setup.sh -i)


# XXX: checkout angr to version at the submission of SAILR
# if you want the latest version of angr-decompiler, with future fixes, remove this block
RUN pip3 install sh && (cd ./angr-dev && \
    ./admin/checkout_at.py a8bab649cfc18912d5bb3ce70ef57a4ae4039f53 && \
    cd ./angr && \
    git remote add mahaloz https://github.com/mahaloz/angr-sailr.git && \
    git fetch mahaloz && \
    git checkout mahaloz/sailr)

ENTRYPOINT ["python3", "/SAILR/scripts/run_angr_dec.py"]