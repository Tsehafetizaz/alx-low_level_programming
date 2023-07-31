#include "main.h"

/**
* _strstr - locates a substring
* @haystack: the string to be scanned
* @needle: the string to be found
* Return: a pointer to the beginning of the located substring,
* or NULL if the substring is not found
*/
char *_strstr(char *haystack, char *needle)
{
char *h, *n;
while (*haystack)
{
h = haystack;
n = needle;
while (*haystack && *n && *haystack == *n)
{
haystack++;
n++;
}
if (!*n)
return (h);
haystack = h + 1;
}
return (NULL);
}
