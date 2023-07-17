cmake_minimum_required(VERSION 3.10)  # or your minimum version
project(UnityTests)

add_library(Unity STATIC
    unity.c)
 
target_include_directories(Unity PUBLIC
   . 
)
