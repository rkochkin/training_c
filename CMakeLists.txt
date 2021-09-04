cmake_minimum_required(VERSION 3.16)
project(training C)

set(CMAKE_C_STANDARD 11)
include_directories(include)
#include/environment.h include/qsort.h
add_executable(
        training
        main.c
        src/sort.c
        src/environment.c
        src/binsearch.c
        src/recursion.c
        src/variadic.c
        src/permutation.c
)