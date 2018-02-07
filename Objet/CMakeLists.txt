cmake_minimum_required (VERSION 2.8.11)
project (Perceptron)
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
# add_subdirectory (src)
# add_executable(main src/main.cpp)

#enable_testing ()
#add_subdirectory (test)

include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.cpp")

add_executable(perceptron ${SOURCES})
