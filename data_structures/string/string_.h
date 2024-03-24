//
// Created by Kirill on 02.03.2024.
//

#ifndef CODE_STRING__H
#define CODE_STRING__H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <ctype.h>


#define ASSERT_STRING(expected, got) assert_string(expected, got, __FILE__, __FUNCTION__, __LINE__)

#define MAX_WORD_SIZE 30
#define MAX_N_WORDS_IN_STRING 100
#define MAX_STRING_SIZE 200

extern char _string_buffer[MAX_STRING_SIZE + 1];


typedef struct word_descriptor {
    char* begin;
    char* end;
} word_descriptor;


typedef struct bag_of_words {
    word_descriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} bag_of_words;

extern bag_of_words _bag;
extern bag_of_words _bag2;


// возвращает длину строки begin
size_t strlen_(const char* begin);


// возвращает адрес элемента ch на участке памяти от begin до end
char* find(char *begin, char* end, int ch);


// возвращает адрес первого не пробельного символа, начиная с begin
char* find_non_space(char* begin);


// возвращает адрес первого пробельного символа, начиная с begin
char* find_space(char* begin);


// возвращает адрес первого не пробельного символа, начиная справа-налево от r_begin до r_end
char* find_non_space_reverse(char* r_begin, const char* r_end);


// возвращает адрес первого пробельного символа, начиная справа-налево от r_begin до r_end
char* find_space_reverse(char* r_begin, const char* r_end);


// возвращает 0 если строки lhs и rhs равны, либо -1, если lhs меньше rhs, либо 1, если lhs больше rhs
int strcmp_(const char* lhs, const char* rhs);


// записывает объект, находящийся по адресу от begin_source до end_source, начиная с begin_destination
// возвращает адрес последнего скопированного элемента
char* copy(const char* begin_source, const char* end_source, char* begin_destination);


// записывает объект, находящийся по адресу от begin_source до end_source, начиная с begin_destination,
// если он удовлетворяет функции предикату f
// возвращает адрес последнего скопированного элемента
char* copy_if(const char* begin_source, const char* end_source, char* begin_destination, int (*f)(int));



// записывает объект справа-налево, находящийся по адресу от r_begin_source до r_end_source, начиная с begin_destination,
// если он удовлетворяет функции предикату f
// возвращает адрес последнего скопированного элемента
char* copy_if_reverse(const char* r_begin_source, const char* r_end_source, char* begin_destination, int (*f)(int));


// возвращает адрес конца строки
char* get_end_of_string(char* s);


// записывает первое найденное слово строки begin_search в word
// возвращает true, если удалось считать слово
// иначе false
bool get_word(char* begin_search, word_descriptor* word);


// записывает, без пробельного символа, первое найденное слово строки begin_search в word
// возвращает true, если удалось считать слово
// иначе false
bool get_word_without_space(char* begin_search, word_descriptor* word);


// записывает первое найденное справа_налево слово строки начинающийся от r_begin и кончающуюся в r_end в word
// возвращает true, если удалось считать слово
// иначе false
bool get_word_reverse(char* r_begin, char* r_end, word_descriptor* word);


// выводит содержимое структуры word_descriptor
void print_word(word_descriptor word);


// очищает строку от предыдущих объектов
void free_string(char* string);


// очищает память занимаемую структурой bag_of_words
void free_bag(bag_of_words* bag);


void assert_string(const char* expected, char* got,
                   char const* file_name, char const* func_name,
                   int line);


// возвращает true, если word1 и word2 является одинаковыми
// иначе false
bool is_word_equal(word_descriptor word1, word_descriptor word2);


// преобразует word в строку
// преобразование начинается с dest
void word_descriptor_to_string(word_descriptor word, char* dest);


// возвращает true, если word является палиндромом
// иначе false
bool is_palindrome_word(word_descriptor* word);


#endif //CODE_STRING__H
