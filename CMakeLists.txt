cmake_minimum_required(VERSION 3.26)
project(code C)

set(CMAKE_C_STANDARD 11)

add_executable(code main.c
        data_structures/matrix/matrix.h
        data_structures/matrix/matrix.c
        algorithms/task/matrix_transposition.h
        algorithms/task/convert_float.h
        algorithms/task/evaluate_expression.h
        data_structures/string/string_.h
        data_structures/string/string_.c
        data_structures/string/task/letters_belong_string.h
        algorithms/task/filter_word.h
        data_structures/string/task/print_revers_ordered.h
        data_structures/string/task/find_anagram_words.h
        algorithms/task/leave_longest_word.h
)

