#!/bin/bash

rm -rf bld
mkdir bld
cd bld
cmake ..
cmake --build .
cmake --build . --target=appimage

