#include "palindrome.h"

#define MAX_SIZE 20 /* Max array size for unsigned long*/

/**
 * is_palindrome - [ DRIVER ] for checking if n is a palindrome
 *@n: unsigned long int to check
 *
 * Return: true/false
 */

int is_palindrome(unsigned long n)
{
	int length;
	char number[MAX_SIZE] = {0};
	bool result;

	length = ltoa(number, n);
	result = check_palindrome(number, length);

	return (result);
}

/**
 *	ltoa - converts long to array while counting number length
 *@number: container array to fill
 *@n: long number to convert
 *
 * Return: Length of the number
 */

int ltoa(char *number, unsigned long n)
{
	int length;

	for (length = 0; n > 0; length++, n /= 10)
	{
		number[length] = n % 10;
	}

	return (length);
}

/**
 * check_palindrome - checks if number is a palindrome
 *@number: array containing numbers
 *@length: lenght of array to check from index 0
 *
 * Return: true false
 */

bool check_palindrome(char *number, int length)
{
	int start = 0;
	int end = length - 1;

	while (start < end)
	{
		if (number[start] != number[end])
			return (false);
		start++;
		end--;
	}

	return (true);
}
