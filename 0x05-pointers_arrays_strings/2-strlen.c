#include "main.h"

/**
* _strlen - returns the length of a string
* @s: string to be measured
*
* Return: length of the string
*/
int _strlen(char *s)
{
int length = 0;

while (*s != '\0')
{
length++;
s++;
}

return length;
}
