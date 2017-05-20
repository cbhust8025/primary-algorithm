cmake_minimum_required(VERSION 3.7)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp VectorHelper.h StringHelper.h mathHelper.h head.h ListHelper.h TreeHelper.h BackTrackingHelper.h DynamicProgrammingHelper.h GraphHelper.h designHelper.h)
add_executable(LeetCode ${SOURCE_FILES})