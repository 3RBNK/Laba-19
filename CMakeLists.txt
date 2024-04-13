cmake_minimum_required(VERSION 3.26)
project(code C)

set(CMAKE_C_STANDARD 11)

add_executable(code main.c
        data_structures/vector/vector.h
        data_structures/vector/vector.c

        data_structures/matrix/matrix.h
        data_structures/matrix/matrix.c

        data_structures/string/string_.h
        data_structures/string/string_.c

        data_structures/string/task/letters_belong_string.h
        data_structures/string/task/print_revers_ordered.h
        data_structures/string/task/find_anagram_words.h

        algorithms/task/matrix_transposition.h
        algorithms/task/convert_float.h
        algorithms/task/evaluate_expression.h
        algorithms/task/filter_word.h
        algorithms/task/leave_longest_word.h
        data_structures/vector/vector.h
        data_structures/vector/vector.c
        algorithms/task/rearrange_numbers.h
        algorithms/task/transpose_non_symmetric_matrix.h
)

