#include "palindrome.h"
#include <stdio.h>
/**
 * is_palindrome - build the number backwards and check if it is the same
 *@n: unsigned long int to check
 *
 * Return: true/false
 */

int is_palindrome(unsigned long n)
{
	unsigned long backwards = 0;
	unsigned long num;

	for (num = n; num > 0; num = num / 10)
	{
		backwards = (backwards * 10) + (num % 10);
	}

	return (backwards == n);
}
