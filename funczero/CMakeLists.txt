cmake_minimum_required(VERSION 3.21)
project(math_geoandnum)

set(CMAKE_CXX_STANDARD 14)
include_directories(./include)

add_executable(funczero_demo src/funczero.cpp)
target_link_libraries(funczero_demo PRIVATE math_geoandnum)