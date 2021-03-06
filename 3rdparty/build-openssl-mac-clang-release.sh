#!/bin/bash

export OPENSSL_ROOT=`pwd`
export OPENSSL_VERSION="openssl-1.0.2p"

export COMPILER=clang
export OS=mac
export BUILDTYPE=release
export CONCURRENT_JOB=2

# decompress 
rm -fr $OPENSSL_ROOT/$OPENSSL_VERSION
tar -zxvf $OPENSSL_ROOT/$OPENSSL_VERSION.tar.gz -C $OPENSSL_ROOT

# entry openssl dir
cd $OPENSSL_ROOT/$OPENSSL_VERSION

echo "OPENSSL_ROOT = $OPENSSL_ROOT"
./Configure darwin64-x86_64-cc no-shared --prefix=$OPENSSL_ROOT/../lib/$OS/$COMPILER/$BUILDTYPE/openssl

make -j$CONCURRENT_JOB
make install
