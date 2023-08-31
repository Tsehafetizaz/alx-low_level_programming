#include "main.h"

/**
* print_binary - prints the binary representation of a number
* @n: number to convert
* Return: void
*/

void print_binary(unsigned long int n)
{
unsigned long int mask;
int flag;

mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
flag = 0;

while (mask)
{
if ((n & mask) == 0 && flag)
_putchar('0');
else if (n & mask)
{
_putchar('1');
flag = 1;
}
mask >>= 1;
}

if (!flag)
_putchar('0');
}
