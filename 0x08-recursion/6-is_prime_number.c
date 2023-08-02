#include "main.h"

/**
* is_divisible - checks if number is divisible
* @num: the number to be checked
* @div: the divisor
* Return: 1 if the number is not divisible by divisor, otherwise 0
*/
int is_divisible(int num, int div)
{
if (num % div == 0)
{
return (0);
}
else if (div == num / 2)
{
return (1);
}
else
{
return (is_divisible(num, div + 1));
}
}

/**
* is_prime_number - checks if the input integer is a prime number
* @n: the number to be checked
* Return: 1 if the input integer is a prime number, otherwise return 0
*/
int is_prime_number(int n)
{
if (n <= 1)
{
return (0);
}
else if (n >= 2 && n <= 3)
{
return (1);
}
else
{
return (is_divisible(n, 2));
}
}
