#!/bin/sh

# ready zImage
rm zImage
rm kernel.elf
rm ramdisk.img
cp kernel/arch/arm/boot/zImage zImage

# make ramdisk image
cd ramdisk
find . | cpio --quiet -H newc -o | gzip > ../ramdisk.img
cd ..

# make kernel
python mkelf.py -o kernel-unsigned.elf zImage@0x00008000 ramdisk.img@0x1000000,ramdisk

