#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef int bool;

int *find_substring(char const *s, char const **words, int nb_words, int *n);
bool invalid_input(char const *s, char const **words, int nb_words, int *n);
bool fill_buff(int *buff, int nb_words, char const **words, char const *s, size_t n);
void zero_buff(int *buff, int size);

#endif /* SUBSTRING_H */
