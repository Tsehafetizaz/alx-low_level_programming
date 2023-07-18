#include "main.h"

/**
* print_last_digit-  prints the last digit of a number
* @n: The number to be checked
*
* Return: 1 if the number is greater than zero, 0 if the number is zero,
*         -1 if the number is less than zero.
*/
int print_last_digit(int n)
{
int last_digit = n % 10;
if (last_digit < 0)
last_digit *= - 1;
_putchar('0' + last_digit);

return (last_digit);
}

