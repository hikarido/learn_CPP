project(namesAndFamilies CXX)
cmake_minimum_required(VERSION 3.0)
ADD_COMPILE_OPTIONS("-Werror")
SET(CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(Person Person.h Person.cpp)
#add_library(Person_test Person_test.cpp)
SET(TESTS Person_test.cpp)
add_executable(namesAndFamilies main.cpp ${TESTS})

target_link_libraries(namesAndFamilies ${GTEST_LIBRARIES} pthread Person)
