#!/bin/sh
if [ -d "./build" ]; then
	rm -rf ./build
fi
mkdir build

if [ ! -d "./data" ]; then 
	mkdir data
fi

cmake -S . -B build
cmake --build build

