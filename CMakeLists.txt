cmake_minimum_required(VERSION 3.19)
project(jsonparser)

set(CMAKE_CXX_STANDARD 20)

add_executable(jsonparser main.cpp JsonTypes.h JsonTypes.cpp)