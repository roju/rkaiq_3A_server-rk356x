#!/bin/bash

mkdir build
set -e
cd build
cmake ..
sudo make
sudo cp ../rkaiq/all_lib/Release/librkaiq.so /usr/lib
echo "installed library to /usr/lib"