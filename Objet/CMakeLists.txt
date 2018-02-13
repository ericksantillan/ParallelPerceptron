cmake_minimum_required (VERSION 2.8.11)
project (Perceptron)
set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

# add_subdirectory (src)
# add_executable(main src/main.cpp)

#enable_testing ()
#add_subdirectory (test)

include_directories(include)

#Can manually add the sources using the set command as follows:
#set(SOURCES src/mainapp.cpp src/Student.cpp)

#However, the file(GLOB...) allows for wildcard additions:

set(COMMON_SOURCES src/data.cpp src/parallelPerceptron.cpp src/perceptron.cpp src/PerceptronIterParamMix.cpp)
add_executable(main ${COMMON_SOURCES} src/main.cpp)
add_executable(parallel ${COMMON_SOURCES} src/main_parallel.cpp)
add_executable(parammix ${COMMON_SOURCES} src/main_parammix.cpp)


# file(GLOB SOURCES "src/*.cpp")
#
# add_executable(main_parallel ${SOURCES})
#
#
# add_executable(perceptron ${SOURCES})
