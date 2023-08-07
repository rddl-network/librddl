cmake_minimum_required(VERSION 3.11.4)
project (RDDLC)

find_package(Protobuf REQUIRED)

set(TARGET_GROUP main CACHE STRING "Group to build")

add_compile_options(-DuECC_VLI_NATIVE_LITTLE_ENDIAN=0 -Wall -Wextra  -O0 -g --coverage -fsanitize=address -fno-omit-frame-pointer)
SET(CMAKE_EXE_LINKER_FLAGS "-DuECC_VLI_NATIVE_LITTLE_ENDIAN=0 -Wall -Wextra  -O0 -g --coverage -fsanitize=address -fno-omit-frame-pointer ${CMAKE_EXE_LINKER_FLAGS}")
set(CMAKE_BUILD_TYPE Debug)

include_directories("${Protobuf_INCLUDE_DIR}")

add_subdirectory(src)
include(CTest)
add_subdirectory(tests)
