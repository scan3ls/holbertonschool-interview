#include "substring.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

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
	int *indices, step, *buff, s_index, word_index, is_full, s_pos;

	if(invalid_input(s, words, nb_words, n))
		return (FALSE);

	*n = 0, step = strlen(words[0]);
	indices = malloc(sizeof(int) * strlen(s));
	/* buff holds flags for matched words */
	buff = malloc(sizeof(int) * nb_words);

	for (s_index = 0; s[s_index] != '\0'; s_index++)
	{
		zero_buff(buff, nb_words);

		for (word_index = 0; word_index < nb_words; word_index++)
		{
			s_pos = s_index + (word_index * step);
			is_full = fill_buff(buff, nb_words, words, s + s_pos, step);

			if (is_full)
				break;
		}

		if (word_index == nb_words)
			indices[(*n)++] = s_index;
	}

	free(buff);
	return (indices);
}

/**
 * invalid_input - checks for valid input for find_substring
 * @s: src string
 * @words: array of strings of same length
 * @nb_words: length of array of words
 * @n: location storing number of incdices found
 *
 * Return: True / False
 */
bool invalid_input(char const *s, char const **words, int nb_words, int *n)
{
	if (strlen(s) == 0)
		return (TRUE);

	if (ARRAY_SIZE(words) == 0)
		return (TRUE);

	if (nb_words == 0)
		return (TRUE);

	if (n == NULL)
		return (TRUE);

	return (FALSE);
}

/**
 * zero_buff - set all values in an int buffer to zero
 * @buff: array of ints
 * @size: size of buff
 */
void zero_buff(int *buff, int size)
{
	int i;

	for (i = 0; i < size; i++)
	{
		buff[i] = 0;
	}
}

/**
 * fill_buff - check words for matchs to current position in s
 * @buff: array of flags for matched word in words
 * @size: number of words and size of buff
 * @words: array of strings
 * @s: source string
 * @n: number of bytes to check
 *
 * Return: TRUE / False if the buffer is full
 */
bool fill_buff(int *buff, int size, char const **words, char const *s, int n)
{
	int i;

	for (i = 0; i < size; i++)
	{
		if (buff[i] == 0 && strncmp(s, words[i], n) == 0)
		{
			buff[i] = 1;
			break;
		}
	}

	return ((i == size) ? TRUE : FALSE);
}
