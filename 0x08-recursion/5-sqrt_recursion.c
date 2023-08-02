#include "main.h"

/**
* find_root - find the square root of a number.
* @n: the number to calculate the square root of
* @i: the current divisor
* Return: the square root of n or -1 if n does not have a square root
*/
int find_root(int n, int i)
{
if (i * i > n)
{
return (-1);
}
else if (i * i == n)
{
return (i);
}
else
{
return (find_root(n, i + 1));
}
}

/**
* _sqrt_recursion - returns the natural square root of a number.
* @n: the number to calculate the square root of
* Return: the square root of n or -1 if n does not have a square root
*/
int _sqrt_recursion(int n)
{
if (n < 0)
{
return (-1);
}
else
{
return (find_root(n, 1));
}
}
