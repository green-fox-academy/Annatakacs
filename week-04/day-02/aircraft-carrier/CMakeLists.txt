cmake_minimum_required(VERSION 3.13)
project(aircraft_carrier)

set(CMAKE_CXX_STANDARD 14)

add_executable(aircraft_carrier main.cpp aircraft.cpp aircraft.h f16.cpp f16.h f35.cpp f35.h carrier.cpp carrier.h)