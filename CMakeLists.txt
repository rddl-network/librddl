cmake_minimum_required(VERSION 3.11.4)
project(RDDLC)

# Check for Linux platform
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_compile_definitions(LINUX_MACHINE)
endif()

set(TARGET_GROUP main CACHE STRING "Group to build")

# Find protobuf-c
find_package(PkgConfig REQUIRED)
pkg_check_modules(PROTOBUF_C REQUIRED libprotobuf-c)

if(NOT PROTOBUF_C_FOUND)
    message(FATAL_ERROR "protobuf-c library not found")
endif()

# Set the full path to the protobuf-c library
set(PROTOBUF_C_LIBRARY "/usr/lib/aarch64-linux-gnu/libprotobuf-c.so")

message(STATUS "PROTOBUF_C_LIBRARIES: ${PROTOBUF_C_LIBRARIES}")
message(STATUS "PROTOBUF_C_LIBRARY_DIRS: ${PROTOBUF_C_LIBRARY_DIRS}")
message(STATUS "PROTOBUF_C_INCLUDE_DIRS: ${PROTOBUF_C_INCLUDE_DIRS}")
message(STATUS "PROTOBUF_C_LIBRARY: ${PROTOBUF_C_LIBRARY}")

# Set C and C++ flags for position-independent code
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

# Add compile options (removed --coverage)
add_compile_options(-DuECC_VLI_NATIVE_LITTLE_ENDIAN=0 -Wall -Wextra -O0 -g)

# Set linker flags (removed --coverage)
set(CMAKE_EXE_LINKER_FLAGS "-DuECC_VLI_NATIVE_LITTLE_ENDIAN=0 -Wall -Wextra -O0 -g ${CMAKE_EXE_LINKER_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

# Add subdirectory for main source
add_subdirectory(src)

# Include directories
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${PROTOBUF_C_INCLUDE_DIRS}
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/base64
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/proto
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/trezor-crypto
)

link_directories(${PROTOBUF_C_LIBRARY_DIRS})

# Create the shared library from the existing static library
add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/libRDDLC.so
        COMMAND ${CMAKE_C_COMPILER} -shared -o libRDDLC.so
        -Wl,--whole-archive $<TARGET_FILE:RDDLC> -Wl,--no-whole-archive
        ${PROTOBUF_C_LIBRARY}
        -L${PROTOBUF_C_LIBRARY_DIRS}
        -Wl,-rpath,${PROTOBUF_C_LIBRARY_DIRS}
        COMMAND ${CMAKE_STRIP} --strip-unneeded ${CMAKE_BINARY_DIR}/libRDDLC.so
        DEPENDS RDDLC
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Add a custom target to ensure the shared library is built
add_custom_target(RDDLC_shared ALL DEPENDS ${CMAKE_BINARY_DIR}/libRDDLC.so)

# Include CTest and tests
include(CTest)
add_subdirectory(tests)