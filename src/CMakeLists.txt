aux_source_directory(./Core SRC_LIST)
aux_source_directory(./Structure SRC_LIST)
aux_source_directory(./Misc SRC_LIST)
aux_source_directory(./IO SRC_LIST)

add_library(RUtil2 ${SRC_LIST})
target_include_directories(RUtil2 PUBLIC "${CMAKE_SOURCE_DIR}/src")

