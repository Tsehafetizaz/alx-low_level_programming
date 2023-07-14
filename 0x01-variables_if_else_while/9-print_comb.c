#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * This program prints all possible combinations of single-digit numbers,
 * separated by a comma and a space. The numbers are printed in ascending order.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int digit;

for (digit = 0; digit < 10; digit++)
{
putchar(digit + '0'); /* Print the digit character */

if (digit != 9)
{
putchar(','); /* Print comma */
putchar(' '); /* Print space */
}
}

putchar('\n'); /* Print newline character */

return (0);
}

