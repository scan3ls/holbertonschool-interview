/* Description: s="barfoothefoobarman", words=["foo", "bar", "man"] */

#include <stdlib.h>
#include <stdio.h>

#include "substring.h"

#define ARRAY_SIZE(a)	(sizeof(a) / sizeof(a[0]))

int main(void)
{
	char const *s = "barfoothefoobarman";
	char const *words[] = {"foo", "bar", "man"};
	int *indices;
	int n = 0;
	int i;

	indices = find_substring(s, words, ARRAY_SIZE(words), &n);

	printf("Indices -> [");
	for (i = 0; i < n; i++)
	{
		if (i)
			printf(", ");
		printf("%d", indices[i]);
	}
	printf("]\n");
	if (indices)
		free(indices);

	return (EXIT_SUCCESS);
}