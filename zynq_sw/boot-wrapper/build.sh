#!/bin/sh

LINUX=../linux-xlnx
FILESYSTEM=../buildroot-2013.02/output/images/rootfs.cpio.gz

make clean

$LINUX/scripts/dtc/dtc -o blob.dtb -O dtb dts/zynq-zc702-base-trd.dts
cat $LINUX/arch/arm/boot/zImage blob.dtb | dd of=zImage bs=4 conv=sync

make FILESYSTEM=$FILESYSTEM CROSS_COMPILE=$CROSS_COMPILE

