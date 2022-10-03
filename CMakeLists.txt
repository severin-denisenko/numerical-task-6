cmake_minimum_required(VERSION 3.22)
project(numerical_task_6)

set(CMAKE_CXX_COMPILER g++-11)
set(CMAKE_CXX_STANDARD 17)

add_executable(numerical_task_6 main.cpp newton.cpp newton.h algebra.cpp algebra.h)
