//
// Created by Kirill on 23.03.2024.
//

#ifndef CODE_EVALUATE_EXPRESSION_H
#define CODE_EVALUATE_EXPRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>


void generate_expression(const char *file_name) {
    srand(time(NULL));

    FILE *file = fopen(file_name, "w");

    int x1 = rand() % 10;
    int x2 = rand() % 10;
    int x3 = rand() % 10;

    char operators[] = "+-*/";
    char op1 = operators[rand() % 4];
    char op2 = operators[rand() % 4];

    bool one_operation = rand() % 2;

    if (one_operation)
        fprintf(file, "(%d %c %d)", x1, op1, x2);
    else
        fprintf(file, "(%d %c %d) %c %d", x1, op1, x2, op2, x3);

    fclose(file);
}


void evaluate_expression(const char* filename) {
    FILE* file = fopen(filename, "r+");

    int x1, x2, x3;
    char op1, op2;
    char open_bracket, close_bracket;
    float result;

    int amount_element = fscanf(file, "%c%d %c %d%c %c %d", &open_bracket, &x1, &op1, &x2, &close_bracket, &op2, &x3);

    bool two_operation = amount_element == 7 ? true : false;

    switch (op1) {
        case '+':
            result = x1 + x2;
            break;
        case '-':
            result = x1 -x2;
            break;
        case '*':
            result = x1 * x2;
            break;
        case '/':
            if (x2 == 0) {
                fprintf(stderr, "Zero division");
                exit(1);
            }
            result = x1 / x2;
            break;
        default:
            fprintf(stderr,"unknown operation");
            exit(1);
    }

    if (two_operation) {
        switch (op2) {
            case '+':
                result += x3;
                break;
            case '-':
                result -= x3;
                break;
            case '*':
                result *= x3;
                break;
            case '/':
                if (x3 == 0) {
                    fprintf(stderr, "Zero division");
                    exit(1);
                }
                result /= x3;
                break;
            default:
                fprintf(stderr,"unknown operation");
                exit(1);
        }
    }

    fseek(file, 0, SEEK_END);
    fprintf(file, " = %.2f", result);

    fclose(file);
}


#endif //CODE_EVALUATE_EXPRESSION_H