cmake_minimum_required(VERSION 3.13)
project(SegmentTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(segment_tree_rmq segment_tree_rmq.cpp)
add_executable(segment_tree_rsq_lazy segment_tree_rsq_lazy.cpp)
add_executable(segment_tree_rmq_lazy segment_tree_rmq_lazy.cpp)