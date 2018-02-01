#!/bin/bash

set -e

#git clone https://gerrit.fd.io/r/vpp
cp -r /git/work/fdio/vpp -T ./vpp
BASEDIR=$(pwd)
ARTIFACT_BASE=${BASEDIR}/vpp/build-root/install-vpp_debug-native/vpp

cd vpp
#git clean -fdx

#make vpp_uses_dpdk=no bootstrap build

cd $ARTIFACT_BASE/include

find ./svm -name '*.h' | cpio -updm "$THIRDPARTY_BUILD"/include
find ./vlibmemory -name '*.h' | cpio -updm "$THIRDPARTY_BUILD"/include
find ./vppinfra -name '*.h' | cpio -updm "$THIRDPARTY_BUILD"/include
find ./vcl -name '*.h' | cpio -updm "$THIRDPARTY_BUILD"/include

cd $ARTIFACT_BASE/lib64
cp libsvm.a "$THIRDPARTY_BUILD"/lib
cp libvlib.a "$THIRDPARTY_BUILD"/lib
cp libvlibmemoryclient.a "$THIRDPARTY_BUILD"/lib
cp libvppinfra.a "$THIRDPARTY_BUILD"/lib
cp libvppcom.a "$THIRDPARTY_BUILD"/lib
