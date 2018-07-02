project(namesAndFamilies CXX)
cmake_minimum_required(VERSION 3.0)
ADD_COMPILE_OPTIONS("-Werror")
SET(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(namesAndFamilies main.cpp)

target_link_libraries(namesAndFamilies ${GTEST_LIBRARIES} pthread)
