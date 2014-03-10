cmake_minimum_required(VERSION 2.8)
project(RUtil2)

add_definitions(-std=c99 -Wall)

enable_testing()

add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(test)
