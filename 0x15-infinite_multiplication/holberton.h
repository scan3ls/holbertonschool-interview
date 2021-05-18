#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>

#define MAX_NUM_LENGTH 1000

typedef struct Number_s
{
    char *value;
    int length;
    char *reversed;
} Number_t;

int _putchar(char c);

#endif /* HOLBERTON_H */
