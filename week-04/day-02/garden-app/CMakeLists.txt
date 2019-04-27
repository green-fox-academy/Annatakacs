cmake_minimum_required(VERSION 3.13)
project(garden_app)

set(CMAKE_CXX_STANDARD 14)

add_executable(garden_app main.cpp Garden.cpp Garden.h Flower.cpp Flower.h Tree.cpp Tree.h Plant.cpp Plant.h)