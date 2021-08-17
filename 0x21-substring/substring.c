#include "substring.h"

#include "concat_words.c"
#include "create_word.c"

/**
 * find_substring - finds all the possible substrings
 *					containing a list of words, within a given string.
 *
 * @s: is the string to scan
 * @words: is the array of words all substrings must be a concatenation arrangement of
 * @nb_words: is the number of elements in the array words
 * @n: holds the address at which to store the number of elements in the returned array.
 *
 * Return: Allocated array, storing each index in s, at which a substring was found.
 *		   If no solution is found, NULL is returned
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int i, *indices = malloc(sizeof(int) * MAX_INDICES);
	char buff[255], **concat_words = get_concat_words(nb_words);
	// int word_length = get_length(words);
	// int buff_size = word_length * nb_words;

	for (i = 0; i < MAX_INDICES; i++)
		indices[i] = -1;

	for (i = 0; concat_words[i] != NULL; i++)
	{
		// printf("[%d] %s\n", i, concat_words[i]);
		create_word(buff, concat_words[i], words);
		printf("Searching for: %s\n", buff);
		// search_string(s, buff, buff_size, word_length, indices, n);
	}
	(void)s;
	/* FREE concat_words */
	for (i = 0; i < MAX_WORD_COUNT; i++)
		free(concat_words[i]);
	free(concat_words);

	*n = 0;
	return (indices);
}

/**
 * get_length - gets number a chars of word
 * @words: list of words
 * Return: (INT) Number of chars
 */
int get_length(char const **words)
{
	char const *word = words[0];
	int i, count = 0;

	for (i = 0; word[i] != '\0'; i++)
		count++;

	return (count);
}
