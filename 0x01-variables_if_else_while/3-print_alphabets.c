#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Tbet, followed by the uppercase alphabet,
 * a separated by a space, and then followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char lowercase;
char uppercase;

for (lowercase = 'a'; lowercase <= 'z'; lowercase++)
{
putchar(lowercase); /* Print lowercase letter */
}

for (uppercase = 'A'; uppercase <= 'Z'; uppercase++)
{
putchar(uppercase); /* Print uppercase letter */
}

putchar('\n'); /* Print newline character */

return (0);
}

