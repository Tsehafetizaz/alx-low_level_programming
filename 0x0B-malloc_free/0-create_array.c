#include "main.h"
#include <stdlib.h>

/**
* create_array - Creates an array of chars and initializes it with a char.
* @size: The size of the array.
* @c: The char to initialize the array with.
* Return: A pointer to the array, or NULL if it fails or size = 0.
*/
char *create_array(unsigned int size, char c)
{
unsigned int i;
char *array;
if (size == 0)
return (NULL);
array = (char *)malloc(size * sizeof(char));
if (array == NULL)
return (NULL);
for (i = 0; i < size; i++)
array[i] = c;
return (array);
}
