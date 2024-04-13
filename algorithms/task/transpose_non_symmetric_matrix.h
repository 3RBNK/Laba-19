//
// Created by lenovo on 12.04.24.
//

#ifndef CODE_TRANSPOSE_NON_SYMMETRIC_MATRIX_H
#define CODE_TRANSPOSE_NON_SYMMETRIC_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generate_non_symmetric_matrix(const char* filename) {
    srand(time(NULL));

    FILE* file = fopen(filename, "wb");

    int n = rand() % 3 + 2;
    fwrite(&n, sizeof(int), 1, file);

    int amount_matrix = rand() % 3 + 1;

    for (int k = 0; k < amount_matrix; k++) {
        int matrix[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = rand() % 100;
            }
        }
        fwrite(matrix, sizeof(int), n * n, file);
    }

    fclose(file);
}


int is_symmetric(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (matrix[i][j] != matrix[j][i])
                return 0;
    return 1;
}


void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void transpose(int n, int matrix[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(&matrix[i][j], &matrix[j][i]);
}


void transpose_non_symmetric_matrix(const char* filename) {
    FILE* file = fopen(filename, "r+b");
    if (file == NULL) {
        printf("Ошибка при открытии файла.\n");
        return;
    }

    int n;
    if (fread(&n, sizeof(int), 1, file) != 1) {
        printf("Ошибка при чтении порядка матрицы.\n");
        fclose(file);
        return;
    }

    while(1) {
        int matrix[n][n];
        size_t read_count = fread(matrix, sizeof(int), n * n, file);
        if (read_count != n * n) {
            if (feof(file)) {
                break; // Достигнут конец файла
            } else {
                printf("Ошибка при чтении матрицы.\n");
                break;
            }
        }

        if (!is_symmetric(n, matrix)) {
            transpose(n, matrix);
            fseek(file, -(long int)read_count * sizeof(int), SEEK_CUR);
            fwrite(matrix, sizeof(int), read_count, file);
            fseek(file, (long int)read_count * sizeof(int), SEEK_CUR); // Перемещаем указатель вперед
        }
    }

    fclose(file);
}



void print_bin_file_matrix(const char* filename) {
    FILE* file = fopen(filename, "rb");

    int n;
    fread(&n, sizeof(int), 1, file);

    while (!feof(file)) {
        int matrix[n][n];
        if (fread(matrix, sizeof(int), n * n, file) != n * n)
            break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

    fclose(file);
}

#endif //CODE_TRANSPOSE_NON_SYMMETRIC_MATRIX_H
