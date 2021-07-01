cmake_minimum_required(VERSION 3.13)
project(StackQueue)

set(CMAKE_CXX_STANDARD 14)

add_executable(StackQueue main.cpp)
add_executable(stack stack.cpp)
add_executable(queue queue.cpp)
add_executable(queue_using_stack queue_using_stack.cpp)
add_executable(stack_using_queue stack_using_queue.cpp)
add_executable(sort_stack sort_stack.cpp)
add_executable(min_stack min_stack.cpp)