//
// Created by Kirill on 23.03.2024.
//

#ifndef CODE_CONVERT_FLOAT_H
#define CODE_CONVERT_FLOAT_H

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>


void generate_float(const char* filename, int n) {
    srand(time(NULL));

    FILE* file = fopen(filename, "w");
    for (size_t i = 0; i < n; i++)
        fprintf(file, "%f ", 10.0 * rand() / RAND_MAX);

    fclose(file);
}


void convert_float(const char* filename) {
    FILE* file = fopen(filename, "r");

    size_t amount_element = 0;
    size_t temp_size = 2;
    float* temp = malloc(sizeof(float) * temp_size);

    while (!feof(file)) {
        if (amount_element > temp_size) {
            temp_size *= 2;
            temp = realloc(temp, sizeof(float) * temp_size);
        }

        fscanf(file, "%f", &temp[amount_element]);
        amount_element++;
    }

    fclose(file);


    file = fopen(filename, "w");

    for (size_t i = 0; i < amount_element - 1; i++)
        fprintf(file, "%.2f ", temp[i]);


    fclose(file);
    free(temp);
}


#endif //CODE_CONVERT_FLOAT_H
