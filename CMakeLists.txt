cmake_minimum_required(VERSION 3.16)
project(FocalPoint)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_CXX_STANDARD 17)

add_executable(FocalPoint  Recursion.cpp HashMap.cpp HashMap.h main.cpp)