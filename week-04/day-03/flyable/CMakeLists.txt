cmake_minimum_required(VERSION 3.13)
project(flyable)

set(CMAKE_CXX_STANDARD 14)

add_executable(flyable main.cpp flyable.cpp flyable.h animal.cpp animal.h vehicle.cpp vehicle.h bird.cpp bird.h helicopter.cpp helicopter.h)