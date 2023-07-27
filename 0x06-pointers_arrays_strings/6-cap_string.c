#include "main.h"
#include <ctype.h>

/**
* cap_string - capitalizes all words of a string.
* @str: the string to capitalize
*
* Return: the pointer to the string
*/
char *cap_string(char *str)
{
int i;
int new_word = 1;
char separators[] = " \t\n,;.!?\"(){}";
for (i = 0; str[i] != '\0'; i++)
{
if (new_word && isalpha((int)str[i]))
{
str[i] = toupper((int)str[i]);
new_word = 0;
}

if (strchr(separators, str[i]))
{
new_word = 1;
}
}

return (str);
}
