cmake_minimum_required(VERSION 3.21)
project(LW_5b C)

set(CMAKE_C_STANDARD 11)

add_executable(LW_5b main.c libs/data_structures/vector/vector.h libs/data_structures/vector/vector.c)