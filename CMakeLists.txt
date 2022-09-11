cmake_minimum_required(VERSION 3.12)
project(complex-coding-exercises C CXX)
#enable_testing()

# Clear CMAKE_C_FLAGS and CMAKE_CXX_FLAGS. They are set by toolchain file
set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")

#Make testing easier on Windows by setting a runtime directory during build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_VERBOSE_MAKEFILE on)

message(${CMAKE_C_COMPILER})
message(${CMAKE_CXX_COMPILER})

# Assuming GNU compiler. MSVC will be considered in the future
set(CMAKE_C_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_DEBUG_POSTFIX D)

set(CMAKE_C_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

add_compile_options(-Wall -Wextra -Werror -Wno-unknown-pragmas -Wmisleading-indentation -Wno-stringop-truncation -fdiagnostics-show-option -fdiagnostics-color -fPIC -pie -fexceptions -pedantic)

#Set file containing targets of product
set(PRODUCT_TARGET "${PROJECT_NAME}-targets")

# Set a fixed CMAKE_INSTALL_PREFIX if none has been passed externally
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/_build/_install")
ENDIF()

LIST(APPEND CMAKE_PREFIX_PATH "${CMAKE_INSTALL_PREFIX}")
INCLUDE_DIRECTORIES(${CMAKE_INSTALL_PREFIX}/include)
LINK_DIRECTORIES(${CMAKE_INSTALL_PREFIX}/lib)

#Add directories to the project
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/3_sum_0_magic_triplet_exercise ${CMAKE_CURRENT_BINARY_DIR}/3_sum_0_magic_triplet_exercise)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/minimum_number_of_coins_exercise ${CMAKE_CURRENT_BINARY_DIR}/minimum_number_of_coins_exercise)

#Export Target code into the root of current installation dir
install(EXPORT ${PRODUCT_TARGET} DESTINATION .)
