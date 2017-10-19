project(FList)
cmake_minimum_required(VERSION 3.0)
add_compile_options (-std=c++1y)
set(FILES main.cpp flist.hpp flist_test.hpp)
add_executable(${PROJECT_NAME} ${FILES})

