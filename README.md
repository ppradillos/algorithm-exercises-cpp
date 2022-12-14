# List of exercises about algorithms and data structures in C/C++

## Overview

This project implements solutions for some common coding exercises you may find on the Internet to practice and improve your coding skills to e.g.: become a better developer, or to prepare a job interview, or even for fun because... coding is funny!

Those exercises will be focused mainly on algorithms and data structures. Implemented in C/C++ programming language.

## Current status
Work in progress. More exercises will be added over time to the project structure.

## Project structure

**Exercises are considered individual programs themselves**. Therefore, they have their own sub-project folder within the root "algorithm-exercises-cpp" project folder, so they can be treated separately from each other. In addition, they hold a snake case naming convention ending with *_exercise* suffix in the folder's name. E.g.: "3_sum_0_magic_triplet_exercise".

Within every exercise project a specific README file will feature the problem statement, so that the user can have an insight of it, along with the explanation of the solution provided to the problem in order to serve as a guideline to make sense of the implementation, if necessary.

This is a C/C++ project and many executables can be generated out of it, so CMake has been used to create a build environment for all these little projects. The main project features a top-level CMakeList text file in the root folder, and then every single sub-project features its own CMakeList file in the sub-project folder. This way, all sub-projects can be built at once with a single `make` command.

As CMake can be tricky for newcomers, a folder with [build resources](https://github.com/ppradillos/algorithm-exercises-cpp/tree/master/cmake_build_resources) is provided to help users build the project and get all the binaries for further testing. A basic [toolchain file](https://github.com/ppradillos/algorithm-exercises-cpp/blob/master/cmake_build_resources/toolchain-linux.cmake) is also provided in the same folder, but please keep in mind that the path to C/C++ toolchain and compiler flags can vary between environments, so just use it as a reference.

Then, this is the resulting project structure:
* Root project folder
    * CMakeLists.txt
    * cmake_build_resources
        * build scripts
        * toolchain file provided as example
    * project_name1_exercise
        * README text file with statement and solution approach
        * CMAkeLists.txt
        * /src
        * /include
    * project_name2_exercise
        * README text file with statement and solution approach
        * CMAkeLists.txt
        * /src
        * /include
    * project_name3_exercise
        * README text file with statement and solution approach
        * CMAkeLists.txt
        * /src
        * /include
    * ...

Thank to this naming convention, exercises can be easily identified from other elements of the project, such as the build resources.

## Table of exercises

| SR No | Exercise |
| ------ | ------ |
|1 | [3 sum 0 Magic Triplet](https://github.com/ppradillos/algorithm-exercises-cpp/tree/master/3_sum_0_magic_triplet_exercise) |
|2 | [Minimum number of coins](https://github.com/ppradillos/algorithm-exercises-cpp/tree/master/minimum_number_of_coins_exercise) |

## Build and Run the project

Just run the *build.sh* or *rebuild.sh* script within [cmake_build_resources](https://github.com/ppradillos/algorithm-exercises-cpp/tree/master/cmake_build_resources) folder. The scripts assume a toolchain file is provided and located in the same folder, such as the one provided by this project. After building the project, a new "_build" folder should show up in the root folder of the project. If the user navigates into this new folder, an "_install" folder will feature all the binaries generated to run the exercises.

**WARNING!** GNU/Linux assumed to be the build and testing environment. GNU compiler assumed as toolchain. If not the case, please modify both the [root CMakeLists](https://github.com/ppradillos/algorithm-exercises-cpp/blob/master/CMakeLists.txt) file of the project and the [toolchain file](https://github.com/ppradillos/algorithm-exercises-cpp/blob/master/cmake_build_resources/toolchain-linux.cmake) accordingly in your local machine. Other enviroments and toolchains such as Windows and MSVC will be considered in the future.

## License
MIT
