project(Nearest CXX)
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
add_compile_options("-std=c++11")
#add_compile_options("-Werror")
SET(CMAKE_CXX_STANDARD 11)

add_library(CourseraNearest CourseraNearestTask.h CourseraNearestTask.cpp)
add_library(Precompile pchheader.h pchheader.cpp)
add_library(test-FindNearestElement tests-CourseraNearestTask.cpp)

include(PrecompiledHeader.cmake)


add_executable(Nearest tests-main.cpp )


add_precompiled_header(Nearest pchheader.h FORCEINCLUDE)
target_link_libraries(Nearest test-FindNearestElement CourseraNearest)
