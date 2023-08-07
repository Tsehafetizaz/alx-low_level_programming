#include "main.h"
#include <stdlib.h>

/**
* argstostr - concatenates all arguments of the program.
* @ac: argument count
* @av: pointer to array of size ac
* Return: pointer to a new string, or NULL if it fails
*/
char *argstostr(int ac, char **av)
{
int i, j, k = 0, len = 0;
char *str;

if (ac == 0 || av == NULL)
return (NULL);

/* Calculate total length of the concatenated string */
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
len++;
len++;
}

/* Allocate memory */
str = malloc(sizeof(char) * (len + 1));
if (str == NULL)
return (NULL);

/* Populate the new string */
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++, k++)
str[k] = av[i][j];
str[k++] = '\n';
}
str[k] = '\0';

return (str);
}
