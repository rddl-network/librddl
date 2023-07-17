cmake_minimum_required(VERSION 3.11.4)
project (RDDLC)

set(TARGET_GROUP main CACHE STRING "Group to build")

add_compile_options(-DuECC_VLI_NATIVE_LITTLE_ENDIAN=0 -Wall -Wextra  -O0 -g --coverage -fsanitize=address -fno-omit-frame-pointer)
SET(CMAKE_EXE_LINKER_FLAGS "-DuECC_VLI_NATIVE_LITTLE_ENDIAN=0 -Wall -Wextra  -O0 -g --coverage -fsanitize=address -fno-omit-frame-pointer ${CMAKE_EXE_LINKER_FLAGS}")

add_subdirectory(src)
include(CTest)
add_subdirectory(tests)
