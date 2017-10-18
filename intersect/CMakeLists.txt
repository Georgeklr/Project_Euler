cmake_minimum_required (VERSION 2.6)
project(Intersect)

include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(main ${PROJECT_SOURCE_DIR}/src/main.cpp)
