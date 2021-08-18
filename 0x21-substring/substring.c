#include "substring.h"

/**
 * find_substring - does stuff
 * @s: src string
 * @words: array of strings of same length
 * @nb_words: length of array of words
 * @n: location storing number of incdices found
 *
 * Return: array of indices as ints
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indices = malloc(sizeof(int) * 1);

	(void)s;
	(void)words;
	(void)nb_words;

	*n = 1;
	return (indices);
}
