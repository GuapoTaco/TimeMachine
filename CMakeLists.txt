cmake_minimum_required(VERSION 2.6)
project(timemachine)

find_package(Boost COMPONENTS program_options REQUIRED)



add_executable(tmc TMCompiler.cpp)

target_include_directories(tmc PUBLIC ${Boost_PROGRAM_OPTIONS_INCLUDE_DIR})
target_link_libraries(tmc ${Boost_PROGRAM_OPTIONS_LIBRARY})

target_compile_features(tmc PUBLIC
	cxx_right_angle_brackets
)

install(TARGETS tmc RUNTIME DESTINATION bin)
