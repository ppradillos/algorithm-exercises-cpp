cmake_minimum_required(VERSION 3.12)
project(3_sum_0_magic_triplet C CXX)

message("-----------------------------------------------------------")
message("Creating makefile of ${PROJECT_NAME} as ${CMAKE_BUILD_TYPE}")

#Files
set(SOURCES
    src/magic_triplet.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

install(TARGETS ${PROJECT_NAME} EXPORT ${PRODUCT_TARGET}
                RUNTIME DESTINATION bin)