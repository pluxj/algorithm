cmake_minimum_required(VERSION 3.9)
project(./)

set(CMAKE_CXX_STANDARD 11)

add_executable(mysort mysort.cpp mysort.h main.cpp SortTest.h MaxPQ.cpp MaxPQ.h)