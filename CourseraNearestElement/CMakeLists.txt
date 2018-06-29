project(Nearest CXX)
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
add_compile_options("-Werror")
SET(CMAKE_CXX_STANDARD 11)

add_library(CourseraNearest CourseraNearestTask.cpp)

add_executable(Nearest main.cpp)
target_link_libraries(Nearest CourseraNearest)
