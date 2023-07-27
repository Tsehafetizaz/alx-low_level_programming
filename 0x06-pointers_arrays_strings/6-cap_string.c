#include "main.h"

/**
*cap_string - capitalizes all words in a string.
* @str: the string to capitalize.
* Return: pointer to the capitalized string.
*/
char *cap_string(char *str)
{
int i = 0;
int start_word = 1;

while (str[i] != '\0')
{
if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
str[i] == '!' || str[i] == '?' || str[i] == '"' ||
str[i] == '(' || str[i] == ')' || str[i] == '{' ||
str[i] == '}')
{
start_word = 1;
}
else if (start_word == 1 && str[i] >= 'a' && str[i] <= 'z')
{
str[i] = str[i] - 'a' + 'A';
start_word = 0;
}
else
{
start_word = 0;
}
i++;
}
return (str);
}
