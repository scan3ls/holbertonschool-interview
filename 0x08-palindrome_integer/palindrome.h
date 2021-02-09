#ifndef PALINDROME_H
#define PALINDROME_H

#include <stdio.h>

#define MAX_SIZE 20 /* Max array size for unsigned long*/

/**
 * struct num_s - contains number data
 *@n: value of number as unsigned long
 *@length: number of digits
 *@digits: array container for the digits
 */

typedef struct num_s
{
	unsigned long n;
	int length;
	char digits[MAX_SIZE];
} num_t;

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
void ltoa(num_t *num);
bool check_palindrome(num_t *num);

#endif /* PALINDROME_H*/
