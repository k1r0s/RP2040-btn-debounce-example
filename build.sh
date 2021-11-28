#!/bin/sh

rm -rf build/*
mkdir -p build
cd build/
cmake ..
make
# sudo mount /dev/sdb1 /mnt/pico-mnt/
# sudo cp main.uf2 /mnt/pico-mnt/
# sudo umount /mnt/pico-mnt/
