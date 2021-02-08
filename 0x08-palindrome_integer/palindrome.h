#ifndef PALINDROME_H
#define PALINDROME_H

#include <stdio.h>

/**
 * enum boolean - defines true false booleans
 *@false: 0 = false
 *@true: 1 = true
 */

enum boolean
{
	false, true
};

typedef int bool;

/* 0-is_palindrome.c */
int is_palindrome(unsigned long n);
int ltoa(char* number, unsigned long n);
bool check_palindrome(char *number, int length);

#endif /* PALINDROME_H*/
