cmake_minimum_required(VERSION 3.26)
project(graph_cpp)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(
        graph_cpp
        main.cpp
        vertex/vertex.cpp
        graph/graph.cpp
        utils.h
)