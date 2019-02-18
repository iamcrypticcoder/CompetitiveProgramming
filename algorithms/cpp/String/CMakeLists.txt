cmake_minimum_required(VERSION 3.13)
project(String)

set(CMAKE_CXX_STANDARD 14)

add_executable(kmp kmp.cpp)
add_executable(longest_non_repeating_substring longest_non_repeating_substring.cpp)
add_executable(manacher_algorithm manacher_algorithm.cpp)
add_executable(robin_karp robin_karp.cpp)
add_executable(trie trie.cpp)