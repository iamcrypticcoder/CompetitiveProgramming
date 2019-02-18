cmake_minimum_required(VERSION 3.13)
project(Math)

set(CMAKE_CXX_STANDARD 14)

add_executable(bigint bigint.cpp)
add_executable(floyd_cycle_finding floyd_cycle_finding.cpp)
add_executable(gaussian_elimination gaussian_elimination.cpp)
add_executable(utility_methods utility_methods.cpp)