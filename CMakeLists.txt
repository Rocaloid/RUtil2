cmake_minimum_required(VERSION 2.8.4)
project(RUtil2)

add_definitions(-std=gnu99 -O0 -Wall -g)

enable_testing()

add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(test)
