#include "substring.h"

int main()
{
    int i_concat, i_words, i_buff, num, c;

    char buff[255] = {0};
    
    char *one = "Zero", *two = "One", *three = "Two";
    char const **words = malloc(sizeof(char *) * 4);
    words[0] = one, words[1] = two;
    words[2] = three, words[3] = NULL;

    char *a1 = "0:1:2" , *a2 = "0:2:1",*b1 = "1:0:2", *b2 = "1:2:0",*c1 = "2:0:1", *c2 = "2:1:0";
    char **concat_words = malloc(sizeof(char *) * 7);
    concat_words[0] = a1, concat_words[1] = a2, concat_words[2] = b1;
    concat_words[3] = b2, concat_words[4] = c1, concat_words[5] = c2, concat_words[6] = NULL;

    for (i_concat = 0; concat_words[i_concat] != NULL; i_concat++)
    {
        create_word(buff, concat_words[i_concat], words);
        printf("%s - %s\n", concat_words[i_concat], buff);
    }

    free(words);
    free(concat_words);

    return (1);
}
