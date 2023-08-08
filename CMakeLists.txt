cmake_minimum_required(VERSION 3.24)
project(MultithreadedProgramming_VK)

file(GLOB sources  *.cpp  *.h)

set(CMAKE_CXX_STANDARD 17)

add_executable(MultithreadedProgramming_VK ${sources})
