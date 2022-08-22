#!/bin/bash

# Setting a constant to get relative path to the root folder of the project. Change if necessary
PROJECT_ROOT_FOLDER=..

rm -rf $PROJECT_ROOT_FOLDER/CMakeFiles/*
rm -rf $PROJECT_ROOT_FOLDER/_build/*
echo "CMake and project cache clean"
