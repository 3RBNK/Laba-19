//
// Created by Kirill on 14.04.2024.
//

#ifndef CODE_REMOVE_TRUE_POLYNOMIAL_H
#define CODE_REMOVE_TRUE_POLYNOMIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../../data_structures/vectorVoid/vectorVoid.h"


typedef struct monomial {
    size_t degree;
    double coefficient;
} monomial;


void generate_polynomial(const char* filename) {
    srand(time(NULL));

    FILE* file = fopen(filename, "wb");

    int amount_polynomial = rand() % 5 + 2;

    for (int k = 0; k < amount_polynomial; k++) {
        int amount_monomial = rand() % 5 + 1;

        monomial mono;
        for (int i = 0; i <= amount_monomial; i++) {
            mono.degree = amount_monomial - i;
            mono.coefficient = 2.0 * rand() / RAND_MAX - 1.0;

            fwrite(&mono, sizeof(monomial), 1, file);
        }
    }

    fclose(file);
}


double get_monomial_value(monomial mono, double x) {
    return pow(x, mono.degree) * mono.coefficient;
}


void remove_true_polynomial(const char* filename, double x) {
    vectorVoid v = createVectorV(16, sizeof(monomial));

    FILE* file = fopen(filename, "rb");

    monomial mono;
    while (fread(&mono, sizeof(monomial), 1, file) == 1)
        pushBackV(&v, &mono);

    fclose(file);


    file = fopen(filename, "wb");

    monomial m;
    vectorVoid temp = createVectorV(8, sizeof(monomial));
    double result = 0;
    for (size_t i = 0; i < v.size; i++) {
        getVectorValueV(&v, i, &m);
        pushBackV(&temp, &m);
        result += get_monomial_value(m, x);

        if (m.degree == 0) {
            if (fabs(result) >= 0.001) {
                monomial temp_mono;
                for (size_t j = 0; j < temp.size; j++) {
                    getVectorValueV(&temp, j, &temp_mono);
                    fwrite(&temp_mono, sizeof(monomial), 1, file);
                }
            }

            clearV(&temp);
            result = 0;
        }
    }

    deleteVectorV(&v);
    deleteVectorV(&temp);

    fclose(file);
}


void print_polynomial(const char* filename) {
    FILE* file = fopen(filename, "rb");

    monomial mono;
    while (fread(&mono, sizeof(monomial), 1, file) == 1) {
        printf("%5.2lf * x^%lld + ", mono.coefficient, mono.degree);

        if (mono.degree == 0)
            printf("\b\b \n");
    }

    fclose(file);
}


#endif //CODE_REMOVE_TRUE_POLYNOMIAL_H
