#include "main.h"

/**
* _strchr - locate the first occurrence of a character in a string
* @s: the string to search
* @c: the character to search for
*
* Return: If c is found in s, return a pointer to the first occurrence.
* Otherwise, return NULL.
*/
char *_strchr(char *s, char c)
{
for (; *s != '\0'; s++)
{
if (*s == c)
return (s);
}
if (c == '\0')
return (s);
return (NULL);
}

