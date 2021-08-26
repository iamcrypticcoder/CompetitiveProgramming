cmake_minimum_required(VERSION 3.19)
project(Queue)

set(CMAKE_CXX_STANDARD 14)

add_executable(queue_using_linked_list queue_using_linked_list.cpp)
add_executable(queue_using_array queue_using_array.cpp)
add_executable(queue_using_stack_1 queue_using_stack_1.cpp)
add_executable(queue_using_stack_2 queue_using_stack_2.cpp)
add_executable(lru_cache lru_cache.cpp)
add_executable(main main.cpp)
add_executable(stl_priority_queue stl_priority_queue.cpp)