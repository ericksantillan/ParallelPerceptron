cmake_minimum_required (VERSION 2.8.11)
project (Perceptron)
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
add_subdirectory (src)
add_executable(exe src/main.cpp)

#enable_testing ()
#add_subdirectory (test)
