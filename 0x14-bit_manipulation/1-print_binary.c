#include "main.h"

/**
* print_binary - Prints the binary representation of a number.
* @n: Number to be converted to binary and printed.
*/
void print_binary(unsigned long int n)
{
unsigned long int mask;
int should_print = 0; /* Flag to determine when to start printing */

/* Special case for n = 0 */
if (n == 0)
{
_putchar('0');
return (0);
}

/* Set mask to the most significant bit position */
mask = 1 << (sizeof(unsigned long int) * 8 - 1);

while (mask)
{
if (mask & n)
{
should_print = 1;
_putchar('1');
} else if (should_print)
{
_putchar('0');
}
mask >>= 1;
}
}
