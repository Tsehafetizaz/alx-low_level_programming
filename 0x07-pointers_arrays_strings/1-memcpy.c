#include "main.h"

/**
* _memcpy - a function that copies memory area
* @dest: destination to copy to
* @src: source to copy from
* @n: number of bytes to copy
*
* Return: pointer to destination
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
unsigned int i;
    
for(i = 0; i < n; i++)
{
dest[i] = src[i];
}

return (dest);
}
