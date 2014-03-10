add_executable(
	TestOO
	TestOO/main.c
	TestOO/MyClass.c
)
target_link_libraries(TestOO RUtil2)

add_test(TestOO TestOO)
