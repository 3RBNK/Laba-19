//
// Created by Kirill on 23.03.2024.
//

#ifndef CODE_FILTER_WORD_H
#define CODE_FILTER_WORD_H

#include <stdio.h>

#include "../../data_structures/string/string_.h"
#include "../../data_structures/string/task/letters_belong_string.h"
#include "../../data_structures/string/task/find_anagram_words.h"


bool letters_belong_word(word_descriptor sub_word, word_descriptor word) {
    bool include[26] = {0};

    char* start = word.begin;
    char* end = word.end + 1;

    while (start != end) {
        if (isalpha(*start))
            include[*start - LETTERS_SHIFT] = true;

        start++;
    }

    while (sub_word.begin <= sub_word.end) {
        if (!include[*sub_word.begin - LETTERS_SHIFT])
            return false;

        sub_word.begin++;
    }

    return true;
}



void generate_string(const char* filename, char* source_string) {
    FILE* file = fopen(filename, "w");

    size_t string_length = strlen_(source_string);

    for (size_t i = 0; i <= string_length; i++)
        fprintf(file, "%c", source_string[i]);

    fclose(file);
}


void filter_word(const char* filename, char* source_word) {
    FILE* file = fopen(filename, "r");

    fseek(file, 0, SEEK_END);
    size_t length = ftell(file);
    fseek(file, 0, SEEK_SET);

    fread(_string_buffer, 1, length, file);
    _string_buffer[length] = '\0';

    fclose(file);


    word_descriptor word;
    get_word_without_space(source_word, &word);
    sort_word_letters(&word);

    bag_of_words words = {.size = 0};
    char* begin_search = _string_buffer;
    while (get_word_without_space(begin_search, &words.words[words.size])) {
        begin_search = words.words[words.size].end + 1;
        words.size++;
    }


    file = fopen(filename, "w");

    for (size_t i = 0; i < words.size; i++) {
        if (letters_belong_word(word, words.words[i])) {
            while (words.words[i].begin <= words.words[i].end) {
                fprintf(file, "%c", *words.words[i].begin);
                words.words[i].begin++;
            }
            fprintf(file, " ");
        }
    }

    fprintf(file, "%c", '\0');

    free_string(_string_buffer);
    free_bag(&words);

    fclose(file);
}


#endif //CODE_FILTER_WORD_H
