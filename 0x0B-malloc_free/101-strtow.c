#include "main.h"
#include <stdlib.h>

/**
* count_words - Count the number of words in a string.
* @str: the string to evaluate
* Return: the number of words found
*/
static int count_words(char *str)
{
int count = 0, i = 0;

while (str[i])
{
while (str[i] && str[i] == ' ')
i++;
if (str[i] && str[i] != ' ')
{
count++;
while (str[i] && str[i] != ' ')
i++;
}
}
return (count);
}

char **strtow(char *str)
{
char **words;
int i = 0, j = 0, k, l;
int word_count = count_words(str);
if (!str || !*str || word_count == 0)
return (NULL);
words = malloc(sizeof(char *) * (word_count + 1));
if (!words)
return (NULL);

while (i < word_count && *str)
{
while (*str && *str == ' ')
str++;

j = 0;
while (str[j] && str[j] != ' ')
j++;

words[i] = malloc(j + 1);
if (!words[i])
{
while (i >= 0)
{
free(words[i]);
i--;
}
free(words);
return (NULL);
}

for (k = 0, l = 0; k < j; k++, l++, str++)
words[i][l] = *str;
words[i][l] = '\0';
i++;
}
words[word_count] = NULL;
return (words);
}
