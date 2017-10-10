project(BraceBalance)
cmake_minimum_required(VERSION 3.0)
add_compile_options(-std=c++1y)
aux_source_directory(. SRC_LIST)
set(HEADERS BraceBalance.hpp BraceBalanceTest.hpp)
add_executable(${PROJECT_NAME} ${SRC_LIST} ${HEADERS})

