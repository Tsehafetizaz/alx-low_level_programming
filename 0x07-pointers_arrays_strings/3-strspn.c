#include "main.h"

/**
* _strspn - gets the length of a prefix substring
* @s: string to be scanned
* @accept: string containing the characters to match
* 
* Return: number of bytes in the initial segment of s
* which consist only of bytes from accept
*/
unsigned int _strspn(char *s, char *accept)
{
unsigned int i, j;

for (i = 0; s[i]; i++)
{
for (j = 0; accept[j]; j++)
{
if (s[i] == accept[j])
break;
}

/* If we've gone through all of accept and found no match,
* return the number of matches from the start of the string */
if (!accept[j])
return (i);
}

return (i);
}
