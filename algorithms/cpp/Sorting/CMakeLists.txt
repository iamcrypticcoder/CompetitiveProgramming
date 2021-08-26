cmake_minimum_required(VERSION 3.13)
project(Sorting)

set(CMAKE_CXX_STANDARD 14)

add_executable(merge_sort merge_sort.cpp)
add_executable(insertion_sort insertion_sort.cpp)
add_executable(bubble_sort bubble_sort.cpp)
add_executable(heap_sort heap_sort.cpp)
add_executable(counting_sort counting_sort.cpp)
add_executable(radix_sort radix_sort.cpp)
add_executable(bucket_sort bucket_sort.cpp)