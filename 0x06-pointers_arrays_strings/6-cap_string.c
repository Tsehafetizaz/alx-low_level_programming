#include "main.h"
/**
* cap_string - Capitalizes all words of a string.
* @s: The string to change.
*
* This function converts the first letter of each word
* in the string to uppercase if it is a lowercase letter.
*
* A "word" is defined as a sequence of characters separated
* by one of the following: space, tabulation, new line, ,, ;, ., !, ?, ", (, ), {, or }
*
* Return: Pointer to the modified string.
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
if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == ',' || s[i] == ';' || s[i] == '.' || s[i] == '!' || s[i] == '?' || s[i] == '"' || s[i] == '(' || s[i] == ')' || s[i] == '{' || s[i] == '}')
{
new_word = 1;
}
else
{
new_word = 0;
}
i++;
}
return (s);
}

