#include "substring.h"

#define TRUE 1
#define FALSE 0

/**
 * search_str - search string s for indices with substring stored in buffer buff
 * @s: source string
 * @buff: pointer to substring
 * @buff_size: size of buff
 * @step: bytes to next substring in s
 * @indices: storage location for found indices
 * @n: pointer to the length of indices
 * Return: void
 */
void search_string(
    char const *s, char *buff, int buff_size,
    int step, int *indices, int *n
)
{
    int s_i;

    for (s_i = 0; s[s_i] != '\0'; s_i += step)
    {
        if (match((s + s_i), buff, buff_size))
        {
            add_index(indices, s_i);
            (*n)++;
        }
    }
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
            return (FALSE);
    }

    return (TRUE);
}

/**
 * add_index - add index to indicies
 * @indicies: pointer to array of indicies
 * @index: index to add to indicies
 * Return: void
 */
void add_index(int *indices, int index)
{
    int i;
    for (i = 0; indices[i] != -1; i++)
        ;

    indices[i] = index;
}
