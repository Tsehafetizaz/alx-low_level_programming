#include "main.h"

/**
* cap_string - capitalizes all words of a string.
* @str: the string to capitalize
*
* Return: the pointer to the string
*/
int is_alpha(char c) {
return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int to_upper(char c) {
if (c >= 'a' && c <= 'z')
return c - 'a' + 'A';
return c;
}

int is_separator(char c) {
char separators[] = " \t\n,;.!?\"(){}";
for (int i = 0; separators[i]; i++) {
if (separators[i] == c) return 1;
}
return 0;
}


char *cap_string(char *str)
{
int i;
int new_word = 1;

for (i = 0; str[i] != '\0'; i++)
{
if (new_word && is_alpha(str[i]))
{
str[i] = to_upper(str[i]);
new_word = 0;
}

if (is_separator(str[i]))
{
new_word = 1;
}
}

return (str);
}
