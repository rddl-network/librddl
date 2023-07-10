cmake_minimum_required(VERSION 3.10)  # or your minimum version
project(UnityTests)

add_library(Unity STATIC
    unity.c
        ../test_rddl_cid.cpp ../../src/rddl_cid/rddl_cid.cpp)
 
target_include_directories(Unity PUBLIC
   . 
)
