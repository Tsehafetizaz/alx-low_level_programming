#include "main.h"
#include <stdlib.h>

/**
* str_concat - Concatenates two strings.
* @s1: First string.
* @s2: Second string.
* Return: A pointer to the concatenated string or NULL if memory allocation
*/
char *str_concat(char *s1, char *s2)
{
unsigned int i, j, len1 = 0, len2 = 0;
char *concat_str;

if (!s1)
s1 = "";
if (!s2)
s2 = "";

while (s1[len1])
len1++;
while (s2[len2])
len2++;

concat_str = (char *)malloc(len1 + len2 + 1);
if (!concat_str)
return (NULL);

for (i = 0; i < len1; i++)
concat_str[i] = s1[i];

for (j = 0; j < len2; j++)
concat_str[i + j] = s2[j];

concat_str[i + j] = '\0';

return (concat_str);
}
