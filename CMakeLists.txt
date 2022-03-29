# Specify the minimum version of CMake that can run this script
cmake_minimum_required(VERSION 3.12)

# Project name and version
project(MDSA VERSION 1.0 LANGUAGES C)

#adding cmocka library 
include("${CMAKE_CURRENT_SOURCE_DIR}/lib/FetchCMocka.cmake")

# Compile the passed source files into an executable 
add_executable(MDSA 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c")
target_compile_features(MDSA PRIVATE c_std_99)

#adding add library

add_library(
    add
    "${CMAKE_CURRENT_SOURCE_DIR}/include/add.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/add.c"   
)

add_library(
    add_t
    "${CMAKE_CURRENT_SOURCE_DIR}/test/add/add_test.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/test/add/add_test.c"
)


#link add to main 
target_link_libraries(add_t PRIVATE add cmocka-static)
target_link_libraries(MDSA PRIVATE cmocka-static add_t)


#add testing with cmocka
enable_testing()
add_test(NAME MDSA COMMAND MDSA)

# Set the output directory for executables
set_target_properties(MDSA
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

