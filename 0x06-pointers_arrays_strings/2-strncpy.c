# include "main.h"

/* 
**_strncpy copies a string.
*dest *src are two strings
*return value
*/



char *_strncpy(char *dest, char *src, int n);
{

char *src[40];
char *dest[12];

memset(*dest, '\0', sizeof(*dest));
_strcpy(*src, "Hello World");
_strncpy(*dest, *src, sizeof(*dest)-1);

printf("Final copied string : %s\n", *dest);


return (*dest);

}
