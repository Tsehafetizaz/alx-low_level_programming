#include "main.h"
/**
* string_nconcat - Concatenates two strings.
* @s1: The first string.
* @s2: The second string.
* @n: The number of bytes from `s2` to concatenate to `s1`.
* Return: a pointer to the concatenated string.
*/
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    /* ... function implementation ... */
}
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *concat;
unsigned int i = 0, j = 0, len_s1 = 0, len_s2 = 0;
if (!s1)
s1 = "";
if (!s2)
s2 = "";
while (s1[len_s1])
len_s1++;
while (s2[len_s2])
len_s2++;
/* If n >= len_s2, use entire s2 */
if (n >= len_s2)
n = len_s2;
/* Allocate memory for concatenated string */
concat = malloc(len_s1 + n + 1);   /* +1 for '\0' terminator */
if (!concat)
return (NULL);   /* return NULL if malloc fails */
/* Copy s1 to concat */
while (s1[i])
{
concat[i] = s1[i];
i++;
}
/* Copy first n characters of s2 to concat */
while (j < n)
{
concat[i + j] = s2[j];
j++;
}
/* Null terminate the concatenated string */
concat[i + j] = '\0';
return (concat);
}
