#include "substring.h"


/**
 * get_concat_words - get the schema for a possible permutations of words
 * @nb_words: numbers of words
 *
 * Example 0 1 =>
 * 0:1
 * 1:0
 *
 * Return: list of combinations
 */
char **get_concat_words(int nb_words)
{
	char **concat_words = malloc(sizeof(char *) * MAX_WORD_COUNT);
	int i = 0;
	FILE *fp;
	char *flag = (char *)1, *buff = malloc(sizeof(char) * 255);
	char cmd[20] = "./generator.py ";

	cmd[15] = '0' + (nb_words / 10);
	cmd[16] = '0' + nb_words % 10;
	system(cmd);
	sleep(1);

	fp = fopen("data.txt", "r");
	if (fp)
	{
		while(flag)
		{
			flag = fgets(buff, 255, (FILE *)fp);
			if (flag == NULL)
				break;

			concat_words[i++] = buff;
			buff = malloc(sizeof(char) * 255);
		}
		fclose(fp);
		remove("data.txt");
	}

	free(buff);
	return (concat_words);
}
