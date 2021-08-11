#include "regex.h"
#include <stdio.h>

/**
 * regex_match - simple regex match using '.' and '*'
 * @str: string to search
 * @pattern: string with regex rules to match with
 *
 * Return: 1 if match else 0
 */
int regex_match(char const *str, char const *pattern)
{
	if (AT_END(str))
	{
		if (AT_END(pattern))
			return (TRUE);
		if (STAR_RULE(pattern))
			return (regex_match(str, pattern + 2));
		if (DOT_RULE(pattern))
			return (FALSE);
	}

	if (STAR_RULE(pattern))
	{
		/* Assume char count of zero w/ star */
		if (regex_match(str, pattern + 2))
			return (TRUE);

		if (SAME_CHAR(str, pattern) || DOT_RULE(pattern))
			return (regex_match(str + 1, pattern));

		return (regex_match(str, pattern + 2));
	}

	if (NOT_SAME_CHAR(str, pattern) && NOT_DOT_RULE(pattern))
		return (FALSE);

	return (regex_match(str + 1, pattern + 1));
}
