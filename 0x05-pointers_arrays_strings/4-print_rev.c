#include "main.h"

/**
 * print_rev - prints a string, in reverse, followed by a new line
 * @s: the string to print in reverse
 *
 * Return: void
 */
void print_rev(char *s)
{
int i;

// find the length of the string
while (s[length] != '\0')
{
    length++;
}

// print the string in reverse
for (i = length - 1; i >= 0; i--)
{
    _putchar(s[i]);
}

// print a newline
_putchar('\n');

}

