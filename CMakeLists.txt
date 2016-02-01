cmake_minimum_required(VERSION 3.0)
project(timemachine)

find_package(Boost COMPONENTS program_options REQUIRED)

add_subdirectory("src")

if(${BUILD_TEST})
	add_subdirectory("test")
endif()
