#!/bin/bash

cmake -B_build/ -DCMAKE_INSTALL_PREFIX=./_build/_install -DCMAKE_TOOLCHAIN_FILE=../toolchain-linux.cmake
cd _build && make && make install
