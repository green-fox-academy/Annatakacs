cmake_minimum_required(VERSION 3.13)
project(zoo)

set(CMAKE_CXX_STANDARD 14)

add_executable(zoo main.cpp animals.cpp animals.h egglayers.cpp egglayers.h birds.cpp birds.h reptiles.cpp reptiles.h mammals.cpp mammals.h)