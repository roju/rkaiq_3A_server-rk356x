#!/bin/bash

mkdir build
set -e
cd build
cmake ..
make -j4