cmake_minimum_required(VERSION 3.31)
project(lfx_olympia_coding_challenge CXX)
add_executable(describe_object describe_object.cpp)
set_property(TARGET describe_object PROPERTY
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror")
