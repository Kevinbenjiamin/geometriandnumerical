cmake_minimum_required(VERSION 3.21)
project(math_geoandnum)

set(CMAKE_CXX_STANDARD 14)
include_directories(./include)

add_executable(main_imp src/main_imp.cpp)
target_link_libraries(main_imp PRIVATE math_geoandnum)