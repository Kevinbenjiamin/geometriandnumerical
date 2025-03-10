cmake_minimum_required(VERSION 3.21)
project(math_geoandnum)

set(CMAKE_CXX_STANDARD 14)
include_directories(./include)

add_executable(optim_demo src/optimal.cpp)
target_link_libraries(optim_demo PRIVATE math_geoandnum)