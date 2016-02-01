include_directories("./../src")

add_executable(tm_test 
	preprocessor.cpp
)
target_link_libraries(tm_test tmlibs)

