//
// Created by Kirill on 24.03.2024.
//

#ifndef CODE_LEAVE_LONGEST_WORD_H
#define CODE_LEAVE_LONGEST_WORD_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "../../data_structures/string/string_.h"


#define MAX_LINE_SIZE 100

void generate_text_file(const char* filename, int lines, int word, int max_word_size) {
    srand(time(NULL));

    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < word; j++) {
            for (int k = 0; k < rand() % max_word_size + 1; k++) {
                fprintf(file, "%c", 'a' + rand() % 26);
            }
            fprintf(file, " ");
        }
        fprintf(file, "\n");
    }

    fclose(file);
}


void leave_longest_word(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    char buff[MAX_LINE_SIZE] = "";

    char* rec_ptr = _string_buffer;

    fgets(buff, sizeof(buff), file);
    rec_ptr = copy(buff, buff + strlen_(buff) - 1, rec_ptr);
    *rec_ptr++ = ' ';

    size_t amount_word_in_line = 0;
    char* begin_search = _string_buffer;
    while (get_word_without_space(begin_search, &_bag.words[_bag.size])) {
        begin_search = _bag.words[_bag.size].end + 1;
        amount_word_in_line++;
        _bag.size++;
    }

    while (fgets(buff, sizeof(buff), file)) {
        rec_ptr = copy(buff, buff + strlen_(buff) - 1, rec_ptr);
        *rec_ptr++ = ' ';

        while (get_word_without_space(begin_search, &_bag.words[_bag.size])) {
            begin_search = _bag.words[_bag.size].end + 1;
            _bag.size++;
        }
    }

    fclose(file);

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("reading error\n");
        exit(1);
    }

    for (size_t i = 0; i < _bag.size; i += amount_word_in_line) {
        word_descriptor word_max_length = _bag.words[i];
        size_t max_length = word_max_length.end - word_max_length.begin;

        for (size_t j = i + 1; j < i + amount_word_in_line; j++) {
            size_t current_length = _bag.words[j].end - _bag.words[j].begin;

            if (current_length > max_length) {
                word_max_length = _bag.words[j];
                max_length = current_length;
            }
        }

        char* write_ptr = word_max_length.begin;
        while (write_ptr <= word_max_length.end) {
            fprintf(file, "%c", *write_ptr);
            write_ptr++;
        }

        fprintf(file, "\n");
    }

    fclose(file);
}


#endif //CODE_LEAVE_LONGEST_WORD_H
