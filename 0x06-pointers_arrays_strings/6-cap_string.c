#include "main.h"

/**
* cap_string - a function that capitalizes all words of a string
* @s: the string to change
*
* Return: pointer to the string.
*/
char *cap_string(char *s)
{
int i = 0;
int new_word = 1;
while (s[i])
{
if (s[i] >= 'a' && s[i] <= 'z' && new_word)
{
s[i] -= ('a' - 'A');
new_word = 0;
}
if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == ',' || 
s[i] == ';' || s[i] == '.' || s[i] == '!' || s[i] == '?' || 
s[i] == '"' || s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}')
{
new_word = 1;
}
else {
new_word = 0;
}
i++;
}
return (s);
}

