#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * This program prints the lowercase alphabet, followed by a new line,
 * excluding the letters 'q' and 'e'.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char letter;

for (letter = 'a'; letter <= 'z'; letter++)
{
if (letter != 'q' && letter != 'e')
{
putchar(letter); /* Print lowercase letter */
}
}

putchar('\n'); /* Print newline character */

return (0);
}

