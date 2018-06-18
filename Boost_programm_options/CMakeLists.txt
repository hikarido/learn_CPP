project("Simple Pig Latin")
cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-DBOOST_LOG_DYN_LINK")

add_executable(spl main.cpp)
target_link_libraries(spl boost_log pthread boost_program_options)