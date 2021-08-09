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

	if (str[0] == '\0' && pattern[0] == '\0')
		return (1);

	if (str[0] == '\0')
	{
		if (pattern[1] == '*')
			return (regex_match(str, pattern+2));
		if (pattern[0] == '.')
			return (regex_match(str, pattern+1));
	}

	// printf("%s - %s\n", str, pattern);

	if (pattern[1] == '*')
	{
		if (regex_match(str, pattern+2))
			return (1);

		if (str[0] == pattern[0] || pattern[0] == '.')
			return regex_match(str+1, pattern);

		return regex_match(str, pattern+2);
	}

	if (str[0] != pattern[0] && pattern[0] != '.')
		return (0);

	return (regex_match(str+1, pattern+1));
}
