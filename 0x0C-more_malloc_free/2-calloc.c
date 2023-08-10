#include "main.h"
#include <stdlib.h>

/**
* _calloc - Allocates memory for an array and initializes it to zero.
* @nmemb: Number of elements of the array.
* @size: Size of each element in bytes.
* Return: Pointer to the allocated memory.
* NULL if @nmemb or @size is 0 or if malloc fails.
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
unsigned int i, total_size;
char *ptr;

/* Check if nmemb or size is 0 */
if (nmemb == 0 || size == 0)
return (NULL);

/* Calculate total memory size required */
total_size = nmemb * size;

/* Allocate memory using malloc */
ptr = malloc(total_size);
if (ptr == NULL) /* Check if malloc failed */
return (NULL);

/* Initialize the memory to zero */
for (i = 0; i < total_size; i++)
ptr[i] = 0;

return ((void *)ptr);
}
