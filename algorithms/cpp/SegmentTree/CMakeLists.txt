cmake_minimum_required(VERSION 3.13)
project(SegmentTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(segment_tree_rsq_lazy segment_tree_rsq_lazy.cpp)
add_executable(segment_tree_rmq_lazy segment_tree_rmq_lazy.cpp)
add_executable(segment_tree_concise segment_tree_concise.cpp)
add_executable(D.XeniaandBitOperations "problems/D. Xenia and Bit Operations.cpp")
add_executable(Multiplesof3 "problems/Multiples of 3.cpp")
add_executable(FREQUENT-Frequentvalues "problems/FREQUENT - Frequent values.cpp")
add_executable(GSS1 "problems/GSS1 - Can you answer these queries I.cpp")

add_executable(Test problems/Test.cpp)
add_executable(GSS3 "problems/GSS3 - Can you answer these queries III.cpp")