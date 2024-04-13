
//
// Created by lenovo on 12.04.24.
//

#ifndef CODE_GET_BEST_TEAM_H
#define CODE_GET_BEST_TEAM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LENGTH_STRING 200
#define MAX_AMOUNT_SPORTSMAN 20


typedef struct sportsman {
    char name[MAX_LENGTH_STRING];
    double best_result;
} sportsman;


static void generate_name(char* s) {
    int name_length = rand() % 30 + 5;

    char* rec_ptr = s;
    for (int i = 0; i < name_length; i++) {
        *rec_ptr = rand() % 26 + 97;
        rec_ptr++;
    }
    *rec_ptr = '\0';
}


void generate_team(const char* filename, const int n) {
    srand(time(NULL));

    FILE* file = fopen(filename, "wb");

    for (int i = 0; i < n; i++) {
        sportsman s;
        generate_name(s.name);

        s.best_result = (double) rand() / 100;

        fwrite(&s, sizeof(sportsman),1, file);
    }

    fclose(file);
}


void sort_sportsman(sportsman sm[], const int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (sm[j].best_result < sm[j + 1].best_result) {
                sportsman temp = sm[j];
                sm[j] = sm[j + 1];
                sm[j + 1] = temp;
            }
}


void get_best_team(const char* filename, const int n) {
    FILE* file = fopen(filename, "rb");

    sportsman* team = (sportsman*) malloc(MAX_AMOUNT_SPORTSMAN * sizeof(sportsman));

    sportsman* rec_ptr = team;
    int amount_sportsman = 0;
    while (fread(rec_ptr, sizeof(sportsman), 1, file) == 1) {
        rec_ptr ++;
        amount_sportsman++;
    }

    fclose(file);


    file = fopen(filename, "wb");

    sort_sportsman(team, amount_sportsman);

    int amount_in_team = amount_sportsman >= n ? n : amount_sportsman;

    for (int i = 0; i < amount_in_team; i++) {
        fwrite(team + i, sizeof(sportsman), 1, file);
    }

    free(team);
    fclose(file);
}


void print_team(const char* filename) {
    FILE* file = fopen(filename, "rb");

    sportsman s;
    while (fread(&s, sizeof(sportsman), 1, file) == 1) {
        printf("%s %lf", s.name, s.best_result);
        printf("\n");
    }

    fclose(file);
}


#endif //CODE_GET_BEST_TEAM_H
