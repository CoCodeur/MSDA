# Specify the minimum version of CMake that can run this script
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MDSA VERSION 1.0 LANGUAGES C)


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

add_library(
    doublylinkedlist
    "${CMAKE_CURRENT_SOURCE_DIR}/include/doublylinkedlist.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/doublylinkedlist/doublylinkedlist.c"
    )


#--------------------- TESTING ------------------------#
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/test/")

        include("${CMAKE_CURRENT_SOURCE_DIR}/lib/FetchCMocka.cmake")

        #---------------- LINKEDLIST ----------------------#
        add_executable(LINKEDLIST "${CMAKE_CURRENT_SOURCE_DIR}/test/linkedlist/linkedlist_test.c")
        target_link_libraries(LINKEDLIST PRIVATE doublylinkedlist cmocka-static)

        #---------------- STACK ----------------------#
        add_executable(STACK_TEST "${CMAKE_CURRENT_SOURCE_DIR}/test/stack/stack_test.c")
        target_link_libraries(STACK_TEST PRIVATE stack cmocka-static)


        enable_testing()
        add_test(NAME LINKEDLIST COMMAND LINKEDLIST)
        add_test(NAME STACK_TEST COMMAND STACK_TEST)
       

    endif()
    
#---------------------------------------------#

# Set the output directory for executables
set_target_properties(MDSA
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

