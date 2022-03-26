cmake_minimum_required(VERSION 3.21)
project(C_plus)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(C_plus
        Book.cpp
        Book.h
        test.cpp main.cpp)
