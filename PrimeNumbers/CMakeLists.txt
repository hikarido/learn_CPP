project(PrimeNumbers)
cmake_minimum_required(VERSION 2.8)
add_compile_options(-std=c++11)
aux_source_directory(. SRC_LIST)

find_package(Boost REQUIRED)
if(NOT Boost_FOUND)
    message(SEND_ERROR "failed to find Boost")
    return()
else()
    INCLUDE_DIRECTORIES(${BOOST_INCLUDE_DIR})
endif()

add_executable(${PROJECT_NAME} ${SRC_LIST} ${BOOST_INCLUDE_DIR})

