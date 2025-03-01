cmake_minimum_required(VERSION 3.5.0)
project(math_geoandnum VERSION 0.1.0 LANGUAGES C CXX)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

set(PACKAGE_NAME math_geoandnum)
add_library(math_geoandnum INTERFACE)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE math_geoandnum)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(geo_cal)