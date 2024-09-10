cmake_minimum_required(VERSION 3.11.4)
project(RDDLC)

# Check for Linux platform
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    add_compile_definitions(LINUX_MACHINE)
endif()

set(TARGET_GROUP main CACHE STRING "Group to build")

# Set C and C++ flags for position-independent code
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

# Add compile options
add_compile_options(-DuECC_VLI_NATIVE_LITTLE_ENDIAN=0 -Wall -Wextra -O0 -g --coverage -fsanitize=address -fno-omit-frame-pointer)

# Set linker flags
set(CMAKE_EXE_LINKER_FLAGS "-DuECC_VLI_NATIVE_LITTLE_ENDIAN=0 -Wall -Wextra -O0 -g --coverage -fsanitize=address -fno-omit-frame-pointer ${CMAKE_EXE_LINKER_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

# Add subdirectory for main source
add_subdirectory(src)

# Include directories
include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${PROTOBUF_C_INCLUDE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/base64
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/proto
        ${CMAKE_CURRENT_SOURCE_DIR}/libs/trezor-crypto
)

# Create the shared library from the existing static library
add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/libRDDLC.so
        COMMAND ${CMAKE_C_COMPILER} -shared -o libRDDLC.so -Wl,--whole-archive $<TARGET_FILE:RDDLC> -Wl,--no-whole-archive ${PROTOBUF_C_LIBRARY}
        COMMAND ${CMAKE_STRIP} --strip-unneeded ${CMAKE_BINARY_DIR}/libRDDLC.so
        DEPENDS RDDLC
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

# Add a custom target to ensure the shared library is built
add_custom_target(RDDLC_shared ALL DEPENDS ${CMAKE_BINARY_DIR}/libRDDLC.so)

# Include CTest and tests
include(CTest)
add_subdirectory(tests)