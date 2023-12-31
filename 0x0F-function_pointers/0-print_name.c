#include "function_pointers.h"

/*
*print_name: prints a name using a callback function
*@name: name to print
*@f: callback function to use to print the name
*Return: Nothing
*/
void print_name(char *name, void (*f)(char *))
{
if (name == NULL || f == NULL)
return;
f(name);
}
