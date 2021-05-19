#!/bin/sh

sudo apt update;
sudo apt --assume-yes install --no-install-recommends \
    python3-sphinx \
    zlib1g-dev \
    libbz2-dev \
    liblzma-dev \
    libzstd-dev \
    libboost-iostreams1.71-dev
