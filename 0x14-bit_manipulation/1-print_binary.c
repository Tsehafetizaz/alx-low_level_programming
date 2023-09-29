#include "main.h"

/**
* print_binary - prints the binary representation of a number.
* @n: the number
* Return: nothing
*/
void print_binary(unsigned long int n)
{
if (n == 0)
{
_putchar('0');
return;
}

/* Mask to check each bit */
unsigned long int mask = 1;

/* Find the position of the MSB */
while (mask <= n)
{
mask <<= 1;
}

/* Remove the bit left shifted extra from while loop */
mask >>= 1;

/* Iterate through each bit and print */
while (mask)
{
if (n & mask)
_putchar('1');
else
_putchar('0');

mask >>= 1;
}
}
