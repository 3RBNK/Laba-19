//
// Created by Kirill on 23.03.2024.
//

#ifndef CODE_MATRIX_TRANSPOSITION_H
#define CODE_MATRIX_TRANSPOSITION_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../data_structures/matrix/matrix.h"


void generate_random_matrix_file(const char* filename, size_t n) {
    srand(time(NULL));

    FILE* file = fopen(filename, "w");
    fprintf(file, "%lld\n", n);

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            fprintf(file, "%d ", rand() % 10);
        }

        fprintf(file, "\n");
    }

    fclose(file);
}


void transpose_matrix_in_file(const char* filename) {
    FILE* file = fopen(filename, "r");

    size_t n;
    fscanf(file, "%lld", &n);

    matrix matrix = get_mem_matrix((int) n , (int) n);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            fscanf(file, "%d", &matrix.values[i][j]);

    fclose(file);

    file = fopen(filename, "w");
    fprintf(file, "%d\n", n);

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            fprintf(file, "%d ", matrix.values[i][j]);
        }

        fprintf(file, "\n");
    }

    fclose(file);

    free_mem_matrix(&matrix);
}

#endif //CODE_MATRIX_TRANSPOSITION_H
