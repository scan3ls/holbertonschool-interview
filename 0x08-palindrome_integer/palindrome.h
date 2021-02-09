#ifndef PALINDROME_H
#define PALINDROME_H

#include <stdio.h>

#define MAX_SIZE 20 /* Max array size for unsigned long*/

/**
 * struct Number - contains number data
 *@n: value of number as unsigned long
 *@length: number of digits
 *@number: array container for the digits
 */

typedef struct Number
{
	unsigned long n;
	int length;
	char number[MAX_SIZE];
} Number;

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
void ltoa(Number *num);
bool check_palindrome(Number *num);

#endif /* PALINDROME_H*/
