cmake_minimum_required(VERSION 3.19)
project(DSU)

set(CMAKE_CXX_STANDARD 14)

add_executable(DSU main.cpp)
add_executable(dsu_naive dsu_naive.cpp)
add_executable(dsu_path_compression dsu_path_compression.cpp)
add_executable(dsu_union_rank dsu_union_rank.cpp)
add_executable(SPOJ_CLFLARR SPOJ_CLFLARR.cpp)
add_executable(CF_Roads_not_only_in_Berland CF_Roads_not_only_in_Berland.cpp)
add_executable(dsu_distance_to_root dsu_distance_to_root.cpp)