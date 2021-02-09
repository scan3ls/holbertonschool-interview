#include "palindrome.h"

/**
 * is_palindrome - [ DRIVER ] for checking if n is a palindrome
 *@n: unsigned long int to check
 *
 * Return: true/false
 */

int is_palindrome(unsigned long n)
{
	num_t num = { n, 0, {0} };
	bool result;

	ltoa(&num);
	result = check_palindrome(&num);

	return (result);
}

/**
 *	ltoa - converts long to array while counting number length
 *@num: long number to convert
 *
 */

void ltoa(num_t *num)
{
	unsigned long n = num->n;

	for (num->length = 0; n > 0; num->length++, n /= 10)
	{
		num->digits[num->length] = n % 10;
	}
}

/**
 * check_palindrome - checks if number is a palindrome
 *@num: number to check
 *
 * Return: true false
 */

bool check_palindrome(num_t *num)
{
	int start = 0;
	int end = num->length - 1;

	while (start < end)
	{
		if (num->digits[start] != num->digits[end])
			return (false);
		start++;
		end--;
	}

	return (true);
}