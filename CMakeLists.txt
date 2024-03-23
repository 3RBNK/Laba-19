cmake_minimum_required(VERSION 3.26)
project(code C)

set(CMAKE_C_STANDARD 11)

add_executable(code main.c
        data_structures/matrix/matrix.h
        data_structures/matrix/matrix.c
        algorithms/task/matrix_transposition.h
        algorithms/task/convert_float.h
)
