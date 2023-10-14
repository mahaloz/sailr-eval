FROM --platform=linux/amd64 ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive

#
#
# Evaluation Pipeline
#
#

# ===========================================================
# sailr-eval reqs
# ===========================================================

RUN dpkg --add-architecture i386
RUN apt-get update && apt-get -o APT::Immediate-Configure=0 install -y \
        virtualenvwrapper python3-dev python3-pip build-essential libxml2-dev \
        libxslt1-dev git libffi-dev cmake libreadline-dev libtool debootstrap \
        debian-archive-keyring libglib2.0-dev libpixman-1-dev qtdeclarative5-dev \
        binutils-multiarch nasm libc6:i386 libgcc1:i386 libstdc++6:i386 \
        libtinfo5:i386 zlib1g:i386 vim libssl-dev openjdk-8-jdk openjdk-11-jdk \
        openjdk-17-jdk graphviz-dev \
    && apt-get install --no-install-recommends -y apt-utils wget unzip tar clang-format \
    && rm -rf /var/lib/apt/lists/* \
    && mkdir SAILR && mkdir versioned_tools && mkdir tools

# copy the local SAILR pip project and install 
COPY ./sailreval /SAILR/sailreval
COPY ./*.py /SAILR/
COPY ./setup.cfg /SAILR/
# also installs joern
RUN pip3 install -e ./SAILR

#
#
# Versioned Tools
# 
#

WORKDIR versioned_tools

# ===========================================================
# angr decompiler (SAILR version)
# ===========================================================

# make it easier to install
RUN apt update && apt install python-is-python3 -y

# install angr, and all angr-packages, from the repos (for checkout ability)
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

# ===========================================================
# Ghidra 10.1
# ===========================================================

RUN wget https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_10.1_build/ghidra_10.1_PUBLIC_20211210.zip && \
    unzip ghidra_10.1_PUBLIC_20211210.zip
ENV PATH "/versioned_tools/ghidra_10.1_PUBLIC/support/:$PATH"
    
# any mounted tools take precedence on path
ENV PATH "/tools/:$PATH"
WORKDIR /SAILR
RUN git config --global --add safe.directory /SAILR
ENV FORCE_UNSAFE_CONFIGURE=1


#
#
# Evaluation targets requirements for compilation 
#
#

# ===========================================================
# compilation requirements (add more below) 
# ===========================================================

# coreutils & compiler reqs
RUN apt-get install -y apt-utils bison autopoint gettext gperf rsync texinfo libcap-dev libacl1-dev libssl-dev gcc-9 g++-9 clang flex

#&& \
#wget http://security.ubuntu.com/ubuntu/pool/main/o/openssl/libssl1.1_1.1.1f-1ubuntu2.16_amd64.deb && \
#wget http://security.ubuntu.com/ubuntu/pool/main/o/openssl/libssl-dev_1.1.1f-1ubuntu2.16_amd64.deb && \
#dpkg -i libssl1.1_1.1.1f-1ubuntu2.16_amd64.deb && \
#dpkg -i libssl-dev_1.1.1f-1ubuntu2.16_amd64.deb  && \
#rm libssl1.1_1.1.1f-1ubuntu2.16_amd64.deb && \
#rm libssl-dev_1.1.1f-1ubuntu2.16_amd64.deb

# acl prep: has to reinstall libattr1-dev
RUN rm -rvf /usr/lib/libattr* && \
    rm -rvf /lib/libattr* && \
    apt-get install --no-install-recommends -y libattr1-dev \
        # diffutils reqs
        help2man \
        # audit-userspace reqs    
        golang-openldap-dev \
        # base-passwd reqs
        docbook-utils po4a \
        # dpkg reqs
        libbsd-dev \
        # gnutls reqs 
        gtk-doc-tools nettle-dev libtasn1-6-dev libunistring-dev libev-dev libunbound-dev libp11-kit-dev libtasn1-bin \
        # rsyslog reqs
        libestr-dev libfastjson-dev libgcrypt20-dev libcurl4-openssl-dev

# XXX: this was removed by remains for documentation: fix erorr to NEVER noreturn 
#RUN sed -i 's/__error_noreturn (__status, __errnum, __format, __va_arg_pack ());/__error_alias (__status, __errnum, __format, __va_arg_pack ()); \/\/ SAILR EDIT/g' /usr/include/x86_64-linux-gnu/bits/error.h
#RUN sed -i 's/__error_at_line_noreturn/__error_at_line_alias/g' /usr/include/x86_64-linux-gnu/bits/error.h

# gcc-5 requirements, if this breaks you need to manually install gcc5 on the container or remove this 
RUN printf "\ndeb http://us.archive.ubuntu.com/ubuntu/ xenial main\ndeb http://us.archive.ubuntu.com/ubuntu/ xenial universe\n"  >> /etc/apt/sources.list && \
    apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 40976EAF437D05B5 3B4FE6ACC0B21F32 && \
    apt update && \
    apt install -y gcc-5 g++-5 && \
    head -n -3 /etc/apt/sources.list > /tmp/tmp_source && \
    mv /tmp/tmp_source /etc/apt/sources.list

ENTRYPOINT ["python3", "/SAILR/eval.py"]
