//
// Created by lenovo on 10.04.24.
//

#ifndef CODE_REARRANGE_NUMBERS_H
#define CODE_REARRANGE_NUMBERS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../data_structures/vector/vector.h"


void generate_numbers_array(const char* filename) {
    srand(time(NULL));

    FILE* file = fopen(filename, "wb");

    int amount_numbers = (int) rand() % 10 + 1;

    for (int i = 0; i < amount_numbers; i++) {
        int x = rand() % 200 - 100;
        fwrite(&x, sizeof(int), 1, file);
    }

    fclose(file);
}


void rearrange_numbers(const char* filename) {
    vector positive_numbers = createVector(2);
    vector negative_numbers = createVector(2);

    FILE* file = fopen(filename, "rb");

    int current_number;
    while (fread(&current_number, sizeof(int), 1, file) == 1) {
        if (current_number >= 0)
            pushBack(&positive_numbers, current_number);
        else
            pushBack(&negative_numbers, current_number);
    }

    fclose(file);


    file = fopen(filename, "wb");

    for (int i = 0; i < positive_numbers.size; i++)
        fwrite(positive_numbers.data + i, sizeof(int), 1, file);

    for (int i = 0; i < negative_numbers.size; i++)
        fwrite(negative_numbers.data + i, sizeof(int), 1, file);

    deleteVector(&positive_numbers);
    deleteVector(&negative_numbers);
    fclose(file);
}


void print_numbers_array(const char* filename) {
    FILE* file = fopen(filename, "rb");

    int x;
    while(fread(&x, sizeof(int), 1, file))
        printf("%d ", x);
    printf("\n");

    fclose(file);
}

#endif //CODE_REARRANGE_NUMBERS_H
