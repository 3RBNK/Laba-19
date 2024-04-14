//
// Created by Kirill on 13.04.2024.
//

#ifndef CODE_UPDATE_PRODUCT_H
#define CODE_UPDATE_PRODUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../data_structures/string/string_.h"
#include "../../data_structures/vectorVoid/vectorVoid.h"

#define MAX_LENGTH_STRING 200


typedef struct product {
    char product_name[MAX_LENGTH_STRING];
    int unit_price;
    int total_cost;
    int quantity;
} product;


typedef struct order {
    char order_name[MAX_LENGTH_STRING];
    int quantity;
} order;


void generate_product_and_order(const char* filename1, const char* filename2) {
    srand(time(NULL));

    FILE* file1 = fopen(filename1, "wb");
    FILE* file2 = fopen(filename2, "wb");

    int amount_product = rand() % 15 + 1;
    int amount_order = amount_product % 2 + 1;

    for (int i = 0; i < amount_product; i++) {
        product pr;
        order od;

        pr.unit_price = rand() % 100 + 1;
        pr.quantity = rand() % 20 + 1;
        pr.total_cost = pr.unit_price * pr.quantity;

        int name_length = rand() % 10 + 1;
        char* product_rec_ptr = pr.product_name;
        char* order_rec_ptr = od.order_name;

        for (int j = 0; j < name_length; j++) {
            char ch = rand() % 26 + 97;

            *product_rec_ptr = ch;
            product_rec_ptr++;

            if (amount_order > 0) {
                *order_rec_ptr = ch;
                order_rec_ptr++;
            }
        }

        *product_rec_ptr = '\0';
        if (amount_order > 0) {
            *order_rec_ptr = '\0';
            od.quantity = rand() % 25 + 1;
        }

        fwrite(&pr, sizeof(product), 1, file1);
        if (amount_order > 0)
            fwrite(&od, sizeof(order), 1, file2);

        amount_order--;
    }

    fclose(file1);
    fclose(file2);
}


void update_product(const char* filename1, const char* filename2) {
    vectorVoid v1 = createVectorV(16, sizeof(product));
    vectorVoid v2 = createVectorV(16, sizeof(order));

    FILE* file1 = fopen(filename1, "rb");

    product pr;
    while (fread(&pr, sizeof(product), 1, file1) == 1)
        pushBackV(&v1, &pr);

    fclose(file1);


    FILE* file2 = fopen(filename2, "rb");

    order od;
    while (fread(&od, sizeof(order), 1, file2) == 1)
        pushBackV(&v2, &od);

    for (size_t i = 0; i < v1.size; i++) {
        for (size_t j = 0; j < v2.size; j++) {
            product curr_pr;
            order curr_od;

            getVectorValueV(&v1, i, &curr_pr);
            getVectorValueV(&v2, j, &curr_od);

            if (strcmp_(curr_pr.product_name, curr_od.order_name) == 0) {
                curr_pr.quantity = pr.quantity > od.quantity ? pr.quantity - od.quantity : 0;
                curr_pr.total_cost = pr.unit_price * pr.quantity;
                setVectorValueV(&v1, i, &curr_pr);
            }
        }
    }

    file1 = fopen(filename1, "wb");

    for (size_t i = 0; i < v1.size; i++) {
        product read_pr;
        getVectorValueV(&v1, i, &read_pr);
        if (read_pr.quantity != 0)
            fwrite(&read_pr, sizeof(product), 1, file1);
    }

    deleteVectorV(&v1);
    deleteVectorV(&v2);

    fclose(file1);
}


void print_product_and_order(const char* filename1, const char* filename2) {
    printf("Product: \n");

    FILE* file1 = fopen(filename1, "rb");

    product pr;
    while (fread(&pr, sizeof(product), 1, file1) == 1) {
        printf("name: %s unit price: %d total cost: %d quantity: %d\n", pr.product_name, pr.unit_price, pr.total_cost, pr.quantity);
    }

    fclose(file1);


    printf("Order: \n");

    FILE* file2 = fopen(filename2, "rb");

    order od;
    while (fread(&od, sizeof(order), 1, file2) == 1)
        printf("name: %s quantity: %d\n", od.order_name, od.quantity);

    fclose(file2);
}

#endif //CODE_UPDATE_PRODUCT_H
