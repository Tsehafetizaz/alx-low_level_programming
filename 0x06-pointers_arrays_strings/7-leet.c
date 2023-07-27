#include "main.h"
#include <stdio.h>

/**
* leet - Encodes a string into 1337.
* Letters a and A should be replaced by 4.
* Letters e and E should be replaced by 3.
* Letters o and O should be replaced by 0.
* Letters t and T should be replaced by 7.
* Letters l and L should be replaced by 1.
* @str: The string to be encoded.
*
* Return: The encoded string.
*/
char *leet(char *str)
{
int i, j;
char regular[] = "aeotlAEOTL";
char leet[] = "4307143071";

for (i = 0; str[i] != '\0'; i++)
{
for (j = 0; regular[j] != '\0'; j++)
{
if (str[i] == regular[j])
{
str[i] = leet[j];
break;
}
}
}

return (str);
}

