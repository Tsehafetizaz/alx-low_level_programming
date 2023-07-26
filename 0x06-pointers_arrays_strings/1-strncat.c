#include "main.h"
#include <stdio.h>
/**
 * _strncat - a function that concatenates two strings.
 * @dest: the destination string
 * @src: the source string
 * @n: the maximum number of bytes to use from src
 * 
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
int dest_len, i;
for (dest_len = 0; dest[dest_len] != '\0'; dest_len++)
;
for (i = 0 ; i < n && src[i] != '\0' ; i++)
dest[dest_len + i] = src[i];
dest[dest_len + i] = '\0';
return (dest);
}

