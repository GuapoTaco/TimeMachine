cmake_minimum_required(VERSION 2.6)
project(timemachine)

add_executable(timemachine main.cpp)

install(TARGETS timemachine RUNTIME DESTINATION bin)
