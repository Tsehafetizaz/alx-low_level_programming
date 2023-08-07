#include "main.h"
#include <stdlib.h>

/**
* _strdup - Returns a pointer to a new string which is a duplicate
* of the string str.
* @str: String to be duplicated.
* Return: A pointer to the duplicated string or NULL if str = NULL or if
* insufficient memory was available.
*/
char *_strdup(char *str)
{
unsigned int i, length = 0;
char *duplicate;

if (str == NULL)
return (NULL);

while (str[length])
length++;

duplicate = (char *)malloc(length *sizeof(char) + 1);

if (duplicate == NULL)
return (NULL);

for (i = 0; i < length; i++)
duplicate[i] = str[i];

duplicate[length] = '\0';
return (duplicate);
}
