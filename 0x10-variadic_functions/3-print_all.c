#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
* print_all - prints anything based on a format string.
* @format: a list of types of arguments passed.
* ...: values corresponding to the format.
*/
void print_all(const char * const format, ...)
{
va_list args;
char *str, *sep = "";
unsigned int i = 0;
va_start(args, format);
while (format && format[i])
{
switch (format[i++])
{
case 'c':
printf("%s%c", sep, va_arg(args, int));
break;
case 'i':
printf("%s%d", sep, va_arg(args, int));
break;
case 'f':
printf("%s%f", sep, va_arg(args, double));
break;
case 's':
str = va_arg(args, char*);
if (!str)
str = "(nil)";
printf("%s%s", sep, str);
break;
default:
continue;
}
sep = ", ";
}
printf("\n");
va_end(args);
}
