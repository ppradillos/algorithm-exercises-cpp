#!/bin/bash

# Setting a constant to get relative path to the root folder of the project. Change if necessary
PROJECT_ROOT_FOLDER=..
cmake -S $PROJECT_ROOT_FOLDER -B$PROJECT_ROOT_FOLDER/_build/ -DCMAKE_INSTALL_PREFIX=$PROJECT_ROOT_FOLDER/_build/_install -DCMAKE_TOOLCHAIN_FILE=$PROJECT_ROOT_FOLDER/cmake_build_resources/toolchain-linux.cmake
cd $PROJECT_ROOT_FOLDER/_build && make && make install
