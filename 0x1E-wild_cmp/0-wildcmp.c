#include "holberton.h"
#include <stdio.h>

/**
 * wildcmp - compares strings containing wildcards
 * @s1: base string
 * @s2: pattern to match with
 * Return: 1: true, 0: false
 */
int wildcmp(char *s1, char *s2)
{

	if (s1[0] == '\0' && s2[0] == '\0')
		return (1);

	if (s1[0] == '\0' && s2[0] == '*')
		return (wildcmp(s1, s2+1));

	/* printf("%s == %s\n", s1, s2); */
	if(s2[0] == '*')
	{
		if (wildcmp(s1, s2+1))
			return (1);

		return (wildcmp(s1+1, s2));
	}

	if (s1[0] != s2[0])
		return (0);

	return (wildcmp(s1+1, s2+1));
}