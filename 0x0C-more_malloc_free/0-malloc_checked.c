#include "main.h"
#include <stdlib.h>

/**
* malloc_checked - allocates memory using malloc and checks for any failure
* @b: size of memory to allocate
* Return: pointer to allocated memory or terminate with 98 if fail
*/
void *malloc_checked(unsigned int b)
{
void *ptr;

ptr = malloc(b);

if (!ptr)
exit(98);

return (ptr);
}
