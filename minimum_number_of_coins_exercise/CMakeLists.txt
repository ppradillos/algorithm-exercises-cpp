cmake_minimum_required(VERSION 3.12)
project(minimum_number_of_coins C CXX)

message("-----------------------------------------------------------")
message("Creating makefile of ${PROJECT_NAME} as ${CMAKE_BUILD_TYPE}")

#Files
set(SOURCES
    src/minimum_number_of_coins.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

install(TARGETS ${PROJECT_NAME} EXPORT ${PRODUCT_TARGET}
                RUNTIME DESTINATION bin)