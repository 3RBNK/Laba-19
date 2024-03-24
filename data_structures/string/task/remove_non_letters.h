//
// Created by Kirill on 08.03.2024.
//

#ifndef CODE_REMOVE_NON_LETTERS_H
#define CODE_REMOVE_NON_LETTERS_H

#include <ctype.h>
#include "../string_.h"


void remove_non_letters(char* s) {
    char* end = get_end_of_string(s);
    char* destination = copy_if(s, end, s, isgraph);

    *destination = '\0';
}


void test_1_empty() {
    char s[] = " ";
    remove_non_letters(s);
    ASSERT_STRING("", s);
}


void test_1_non_space() {
    char s[] = "Hi123";
    remove_non_letters(s);
    ASSERT_STRING("Hi123", s);
}


void test_1_space() {
    char s[] = "Hi 123";
    remove_non_letters(s);
    ASSERT_STRING("Hi123", s);
}


void test_1_space_in_border() {
    char s[] = "   Hi 123   ";
    remove_non_letters(s);
    ASSERT_STRING("Hi123", s);
}


void test_1_remove_non_letters() {
    test_1_empty();
    test_1_non_space();
    test_1_space();
    test_1_space_in_border();
}

#endif //CODE_REMOVE_NON_LETTERS_H
