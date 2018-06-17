project("Simple Pig Latin")
cmake_minimum_required(VERSION 3.10)
add_executable(spl main.cpp)

set(CMAKE_CXX_FLAGS "-DBOOST_LOG_DYN_LINK")
target_link_libraries(spl boost_log pthread)