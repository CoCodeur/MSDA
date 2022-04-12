# Specify the minimum version of CMake that can run this script
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MDSA VERSION 1.0 LANGUAGES C)

#adding cmocka library 
include("${CMAKE_CURRENT_SOURCE_DIR}/lib/FetchCMocka.cmake")

# Compile the passed source files into an executable 
add_executable(MDSA 
    "${CMAKE_CURRENT_SOURCE_DIR}/src/main.c")

target_compile_features(MDSA PRIVATE c_std_99)

#------------------ LIBRARY ------------------#

add_library(
    array
    "${CMAKE_CURRENT_SOURCE_DIR}/include/array.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/array/array.c"   
)
add_library(
    graph
    "${CMAKE_CURRENT_SOURCE_DIR}/include/graph.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/graph/graph.c"   
)
add_library(
    hashset
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hashset.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hashset/hashset.c"   
)
add_library(
    hashtable
    "${CMAKE_CURRENT_SOURCE_DIR}/include/hashtable.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/hashtable/hashtable.c"   
)
add_library(
    heap
    "${CMAKE_CURRENT_SOURCE_DIR}/include/heap.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/heap/heap.c"   
)
add_library(
    linkedlist
    "${CMAKE_CURRENT_SOURCE_DIR}/include/linkedlist.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/linkedlist/linkedlist.c"   
)
add_library(
    queue
    "${CMAKE_CURRENT_SOURCE_DIR}/include/queue.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/queue/queue.c"   
)
add_library(
    stack
    "${CMAKE_CURRENT_SOURCE_DIR}/include/stack.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/stack/stack.c"   
)
add_library(
    tree
    "${CMAKE_CURRENT_SOURCE_DIR}/include/tree.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/tree/tree.c"   
)

#---------------------------------------------#

#------------------- TESTS -------------------#
enable_testing()

add_executable(ARRAY "${CMAKE_CURRENT_SOURCE_DIR}/test/array/array_test.c")
target_link_libraries(ARRAY PRIVATE array cmocka-static)
add_test(NAME ARRAY COMMAND ARRAY)

add_executable(GRAPH "${CMAKE_CURRENT_SOURCE_DIR}/test/graph/graph_test.c")
target_link_libraries(GRAPH PRIVATE graph cmocka-static)
add_test(NAME GRAPH COMMAND GRAPH)

add_executable(HASHSET "${CMAKE_CURRENT_SOURCE_DIR}/test/hashset/hashset_test.c")
target_link_libraries(HASHSET PRIVATE hashset cmocka-static)
add_test(NAME HASHSET COMMAND HASHSET)

add_executable(HASHTABLE "${CMAKE_CURRENT_SOURCE_DIR}/test/hashtable/hashtable_test.c")
target_link_libraries(HASHTABLE PRIVATE hashtable cmocka-static)
add_test(NAME HASHTABLE COMMAND HASHTABLE)

add_executable(HEAP "${CMAKE_CURRENT_SOURCE_DIR}/test/heap/heap_test.c")
target_link_libraries(HEAP PRIVATE heap cmocka-static)
add_test(NAME HEAP COMMAND HEAP)

add_executable(LINKEDLIST "${CMAKE_CURRENT_SOURCE_DIR}/test/linkedlist/linkedlist_test.c")
target_link_libraries(LINKEDLIST PRIVATE linkedlist cmocka-static)
add_test(NAME LINKEDLIST COMMAND LINKEDLIST)

add_executable(QUEUE "${CMAKE_CURRENT_SOURCE_DIR}/test/queue/queue_test.c")
target_link_libraries(QUEUE PRIVATE queue cmocka-static)
add_test(NAME QUEUE COMMAND QUEUE)

add_executable(STACK "${CMAKE_CURRENT_SOURCE_DIR}/test/stack/stack_test.c")
target_link_libraries(STACK PRIVATE stack cmocka-static)
add_test(NAME STACK COMMAND STACK)

add_executable(TREE "${CMAKE_CURRENT_SOURCE_DIR}/test/tree/tree_test.c")
target_link_libraries(TREE PRIVATE tree cmocka-static)
add_test(NAME TREE COMMAND TREE)

#---------------------------------------------#

target_link_libraries(MDSA PRIVATE linkedlist)


# Set the output directory for executables
set_target_properties(MDSA
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

