#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define MAX_INDICES 255
#define MAX_WORD_COUNT 100

/* substring.c */
int get_length(char const **words);
int *find_substring(char const *s, char const **words, int nb_words, int *n);

/* concat_words.c */
char **get_concat_words(int nb_words);

/* create_word */
void create_word(char *buff, char *schema, char const **words);

/* search_string.c */
void add_index(int *indices, int index);
int match(char const *s1, char *s2, int size);
void search_string(
    char const *s, char *buff, int buff_size,
    int step, int *indices, int *n
);

#endif /* SUBSTRING_H */