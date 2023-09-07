cmake_minimum_required(VERSION 3.26)
project(Graph)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Graph
        main.cpp
        edge_iterator/edge_iterator.cpp
        vertex/vertex.cpp
        graph/graph.cpp
)
