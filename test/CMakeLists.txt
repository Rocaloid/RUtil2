aux_source_directory(./TestOO Test1)
add_executable(TestOO ${Test1})
target_link_libraries(TestOO RUtil2)

#aux_source_directory(./TestString Test2)
#add_executable(TestString ${Test2})
#target_link_libraries(TestString RUtil2)

#aux_source_directory(./TestSort Test3)
#add_executable(TestSort ${Test3})
#target_link_libraries(TestSort RUtil2)

aux_source_directory(./TestIO Test4)
add_executable(TestIO ${Test4})
target_link_libraries(TestIO RUtil2)

add_test(TestOO TestOO)
#add_test(TestString TestString)
#add_test(TestSort TestSort)
add_test(TestIO TestIO)

get_filename_component(TestDir "." ABSOLUTE)
get_filename_component(TopDir ${CMAKE_SOURCE_DIR} ABSOLUTE)
set(CMAKE_C_FLAGS "-I${TestDir}/TestOO -I${TestDir}/TestString -I${TestDir}/TestSort -I${TestDir}/TestIO -I${TopDir}/src")

