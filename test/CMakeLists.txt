aux_source_directory(./TestOO Test1)
add_executable(_TestOO ${Test1})
target_link_libraries(_TestOO RUtil2)

aux_source_directory(./TestString Test2)
add_executable(_TestString ${Test2})
target_link_libraries(_TestString RUtil2)

aux_source_directory(./TestSort Test3)
add_executable(_TestSort ${Test3})
target_link_libraries(_TestSort RUtil2)

aux_source_directory(./TestIO Test4)
add_executable(_TestIO ${Test4})
target_link_libraries(_TestIO RUtil2)

aux_source_directory(./TestBase64 Test5)
add_executable(_TestBase64 ${Test5})
target_link_libraries(_TestBase64 RUtil2)

aux_source_directory(./TestTune Test6)
add_executable(_TestTune ${Test6})
target_link_libraries(_TestTune RUtil2)

aux_source_directory(./TestCRC32 Test7)
add_executable(_TestCRC32 ${Test7})
target_link_libraries(_TestCRC32 RUtil2)

add_test(TestOO _TestOO)
add_test(TestString _TestString)
add_test(TestSort _TestSort)
add_test(TestIO _TestIO)
add_test(TestBase64 _TestBase64)
add_test(TestTune _TestTune)
add_test(TestCRC32 _TestCRC32)

get_filename_component(TestDir "." ABSOLUTE)
get_filename_component(TopDir ${CMAKE_SOURCE_DIR} ABSOLUTE)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -I${TestDir}/TestOO -I${TestDir}/TestString -I${TestDir}/TestSort -I${TestDir}/TestIO -I${TopDir}/src")

