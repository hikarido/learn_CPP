project(RandGenerator)
cmake_minimum_required(VERSION 3.0)
add_compile_options(-std=c++1y)
set(FILES main.cpp Generator.hpp)
add_executable(${PROJECT_NAME} ${FILES})

