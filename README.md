# List of exercises about algorithms and data structures in C/C++

## Overview

This project implements solutions for some common coding exercises you may find on the Internet to practice and improve your coding skills to e.g.: become a better developer, or to prepare a job interview, or even for fun because... coding is funny!

Those exercises will be focused mainly on algorithms and data structures. Implemented in C/C++ programming language.

## Current status
Work in progress. More exercises will be added over time to the project structure.

## Project structure

**Exercises are considered individual programs themselves**. Therefore, they have their own sub-project folder within the root of the main "algorithm-exercises-cpp" project, so they can be treated separately from each other. In addition, they hold a snake case naming convention and suffix *_exercise* in the folder's name. E.g.: "3_sum_0_magic_triplet_exercise".

Within every exercise project a specific README file will feature information about what problem or exercise is the solution made for, and how the solution has been designed/approached to serve as a guideline to make sense of the implementation, if necessary.

This is a C/C++ project and many executables can be generated out of it, so CMake has been used to create a build environment for all these little projects. The main project features a top-level CMakeList text file, and then every single sub-project features its own CMakeList file in the sub-project folder. This way, all sub-projects can be built at once with a single `make` command.

As CMake can be tricky for newcomers, a folder with [build scripts](https://github.com/ppradillos/algorithm-exercises-cpp/tree/master/build_script_example) is provided to help users build the project and get all the binaries for further testing. A toolchain file is also provided in the same folder, but please keep in mind that the path to C/C++ toolchain and compiler flags can vary between users, so just use it as a reference.

Then, this is the resulting project structure:
* Root project folder
    * CMakeLists.txt
    * build_resources_folder
        * scripts
        * toolchain file provided as example
    * project_name1_exercise
        * CMAkeLists.txt
        * README text file
        * /src
        * /include
    * project_name2_exercise
        * README text file
        * CMAkeLists.txt
        * /src
        * /include
    * project_name3_exercise
        * README text file
        * CMAkeLists.txt
        * /src
        * /include
    * ...

Thank to the naming convention exercises can be identified from other elements of the project, such as the build resources.

## Table of exercises

| SR No | Exercise |
| ------ | ------ |
|1 | [3 sum 0 Magic Triplet](https://github.com/ppradillos/algorithm-exercises-cpp/tree/master/3_sum_0_magic_triplet) |

## Build and Run the project

Just run the "build.sh" or "rebuild.sh" script within "build_resources_folder". The scripts assume a toolchain file is provided and located in the same folder. After building the project, a new "_build" folder should show up in the root folder of the project. If the user navigates into this new folder, an "_install" folder will feature all the binaries generated to run the exercises.

## License
None.