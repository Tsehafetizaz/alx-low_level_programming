#include "main.h"

/**
 * _strcmp - a function that compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 *
 * Return: negative int if s1 < s2, 0 if s1 and s2 are equal, positive if s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1)
{
if (*s1 != *s2)
{
break;
}
s1++;
s2++;
}

return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
