cmake_minimum_required(VERSION 3.13)
project(NumberTheory)

set(CMAKE_CXX_STANDARD 14)

add_executable(eular_number eular_number.cpp)
add_executable(pascal_triangle pascal_triangle.cpp)
add_executable(phi_using_sieve phi_using_sieve.cpp)
add_executable(primes primes.cpp)
add_executable(stirling_number stirling_number.cpp)