# include "main.h"

/* 
**_strcat concatenates two strings.
*dest *src are two strings
*return value
*/



char *_strcat(char *dest, char *src)
{

char *dest[20] = "Hello";
char *src[20] = "World";
*_strcat(*dest, *src);
printf("%s\n", *dest);

return (*dest);

}
