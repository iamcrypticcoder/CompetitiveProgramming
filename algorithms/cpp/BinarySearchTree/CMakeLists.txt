# cmake_minimum_required(VERSION <specify CMake version here>)
project(Temp)

set(CMAKE_CXX_STANDARD 11)

add_executable(count_nodes_given_range binary_tree_to_bst.cpp)
add_executable(binary_tree_to_bst binary_tree_to_bst.cpp)
add_executable(binary_search_tree binary_search_tree.cpp)
add_executable(main main.cpp)
add_executable(floor_ceiling_of_bst floor_ceiling_of_bst.cpp)