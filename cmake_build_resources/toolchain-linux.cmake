###############################################################################
#                    toolchain file for Linux                                 # 
###############################################################################

# Target System
set(CMAKE_SYSTEM_NAME Linux)

# Path to C compiler. Modify to fit your environment
set(C_COMPILER_PATH "/usr/bin/gcc")

#Path to C++ compiler. Modify to fit your environment
set(CXX_COMPILER_PATH "/usr/bin/g++")

# which compilers to use for C and C++
set(CMAKE_C_COMPILER "${C_COMPILER_PATH}")
set(CMAKE_CXX_COMPILER "${CXX_COMPILER_PATH}")

# Compiler flags. Set custom flags here.
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ")

# Setting C/C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED true)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED true)

# here is the target environment located
set(CMAKE_FIND_ROOT_PATH
	  /usr
 )

# Find prefixes and suffixes of libraries within the system (assumed Linux)
set(CMAKE_FIND_LIBRARY_PREFIXES "lib" "")
set(CMAKE_FIND_LIBRARY_SUFFIXES ".so" ".a")
