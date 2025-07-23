#!/bin/sh
if [ -d "./build" ]; then
	rm -rf ./build
fi
mkdir build
mkdir data

cmake -S . -B build
cmake --build build

