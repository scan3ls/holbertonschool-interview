#include "substring.h"

/**
 * create_word - creates a concatinated word from a list of words and a schema
 * @buff: location to store the concatinated word
 * @schema: schema of the word
 * @words: list of words
 * Return: void
 */
void create_word(char *buff, char *schema, char const **words)
{
    int i, num = 0, buff_i = 0, word_i;
    char *word;

    for (i = 0; schema[i] != '\0' && schema[i] != '\n'; i++)
    {
        if (schema[i] != ':')
        {
            num *= 10;
            num += schema[i] - '0';
        }
        else
        {
            word = (char *)words[num];
            for (word_i = 0; word[word_i] != '\0'; word_i++)
                buff[buff_i++] = word[word_i];

            num = 0;
        }
    }

    word = (char *)words[num];
    for (word_i = 0; word[word_i] != '\0'; word_i++)
        buff[buff_i++] = word[word_i];

}
