cmake_minimum_required(VERSION 3.13)
project(farm)

set(CMAKE_CXX_STANDARD 14)

add_executable(farm main.cpp animal.cpp animal.h farm.cpp farm.h)