#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * This program prints all the numbers of base 16 in lowercase,
 * followed by a new line.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int digit;

for (digit = 0; digit < 10; digit++)
{
putchar(digit + '0'); /* Print digit character */
}

for (digit = 0; digit < 6; digit++)
{
putchar(digit + 'a'); /* Print lowercase letter */
}

putchar('\n'); /* Print newline character */

return (0);
}

