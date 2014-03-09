project(RUtil2)
cmake_minimum_required(VERSION 2.6)

option (BuildExec
        "Build as a executable binary" ON)

aux_source_directory(./Core SRC_LIST)
aux_source_directory(./Structure SRC_LIST)

if(BuildExec)
        aux_source_directory(. SRC_LIST)
        add_executable(${PROJECT_NAME} ${SRC_LIST})
else(BuildExec)
        add_library(RUtil2 ${SRC_LIST})
endif(BuildExec)

