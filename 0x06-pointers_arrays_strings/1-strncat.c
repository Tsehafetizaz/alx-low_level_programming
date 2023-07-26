# include "main.h"

/* 
**_strcat concatenates two strings.
*dest *src are two strings
*return value
*/



char *_strncat(char *dest, char *src, int n);
{

char *dest[20] = "Hello";
char *src[20] = "World";
*_strncat(*dest, *src, 10);
printf("%s\n", *dest);

return (*dest);

}
