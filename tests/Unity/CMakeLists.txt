add_library(Unity STATIC
    unity.c
        ../test_rddl_cid.cpp ../../src/rddl_cid/rddl_cid.cpp)
 
target_include_directories(Unity PUBLIC
   . 
)
