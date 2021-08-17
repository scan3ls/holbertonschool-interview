#include "substring.h"

#define TRUE 1
#define FALSE 0

/**
 * compare - compare function for quicksort
 * @a: value a
 * @b: value b
 * Return: 1 , 0, -1
 */
int compare(const void *a, const void *b)
{
		return (*(int *)a - *(int *)b);
}

/**
 * search_str - search string s for indicies with substring stored in buffer buff
 * @s: source string
 * @buff: pointer to substring
 * @buff_size: size of buff
 * @step: bytes to next substring in s
 * @indicies: storage location for found indicies
 * @n: pointer to the length of indicies
 * Return: void
 */
void search_string(
		char const *s, char *buff, int buff_size,
		int step, int *indicies, int *n
)
{
		int s_i;

		for (s_i = 0; s[s_i] != '\0'; s_i += step)
		{
				if (match((s + s_i), buff, buff_size))
				{
						add_index(indicies, s_i);
						(*n)++;
				}
		}

		qsort(indicies, *n, sizeof(int), compare);
		*n = reduce(indicies, *n);
}

/**
 * match - check is s2 is a substring of s1
 * @s1: source string
 * @s2: potential substring of s1
 * @size: size of s2
 * Return: TRUE or FALSE
 */
int match(char const *s1, char *s2, int size)
{
		int i;

		for (i = 0; i < size; i++)
		{
				if(s1[i] != s2[i])
				{
						return (FALSE);
				}
		}

		return (TRUE);
}

/**
 * add_index - add index to indicies
 * @indicies: pointer to array of indicies
 * @index: index to add to indicies
 * Return: void
 */
void add_index(int *indicies, int index)
{
		int i;
		for (i = 0; indicies[i] != -1; i++)
				;

		indicies[i] = index;
}

/**
 * reduce - remove duplicate elements from array of ints
 * @indicies: array to reduce
 * @n: current lenth of indicies
 * Return: new length of indicies as Int
 */
int reduce(int *indicies, int n)
{
	int temp[n];
	int i, j = 0;

	if (n == 0 || n == 1)
		return (n);

	for (i = 0; i < n - 1; i++)
	{
		if (indicies[i] != indicies[i + 1])
		{
			temp[j++] = indicies[i];
		}
	}
	temp[j++] = indicies[n - 1];


	for (i = 0; i < j; i++)
	{
		indicies[i] = temp[i];
	}

	return (j);
}
