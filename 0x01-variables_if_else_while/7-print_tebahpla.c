#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * This program prints the lowercase alphabet in reverse,
 * followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char letter;

for (letter = 'z'; letter >= 'a'; letter--)
{
putchar(letter); /* Print lowercase letter in reverse order */
}

putchar('\n'); /* Print newline character */

return (0);
}

