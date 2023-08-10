#include "main.h"
#include <stdlib.h>

/**
* array_range - Creates an array of integers from min to max.
* @min: Starting value of the array.
* @max: Ending value of the array.
* Return: Pointer to the newly created array or NULL if failure.
*/
int *array_range(int min, int max)
{
int *arr;
int i, length;

/* Check if min is greater than max */
if (min > max)
return (NULL);
/* Calculate the length of the array */
length = max - min + 1;
/* Allocate memory for the array */
arr = malloc(length *sizeof(int));
if (!arr)  /* Check if malloc failed */
return (NULL);

/* Fill the array with values from min to max */
for (i = 0; i < length; i++, min++)
arr[i] = min;

return (arr);
}
