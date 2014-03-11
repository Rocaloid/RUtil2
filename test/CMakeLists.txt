add_executable(
	TestOO
	TestOO/main.c
	TestOO/MyClass.c
	TestOO/MyPrint.c
)
target_link_libraries(TestOO RUtil2)

add_test(TestOO TestOO)

get_filename_component(TestDir "." ABSOLUTE)
get_filename_component(TopDir ${CMAKE_SOURCE_DIR} ABSOLUTE)
set(CMAKE_C_FLAGS "-I${TestDir}/TestOO -I${TopDir}/src")

