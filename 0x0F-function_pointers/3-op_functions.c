#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
* op_add - adds two integers.
* @a: first integer
* @b: second integer
* Return: result of the addition
*/
int op_add(int a, int b)
{
return (a + b);
}
/**
* op_sub - subtracts two integers.
* @a: first integer
* @b: second integer
* Return: result of the subtraction
*/
int op_sub(int a, int b)
{
return (a - b);
}
/**
* op_mul - multiplies two integers.
* @a: first integer
* @b: second integer
* Return: result of the multiplication
*/
int op_mul(int a, int b)
{
return (a * b);
}
/**
* op_div - divides two integers.
* @a: numerator
* @b: denominator
* Return: result of the division. If b0
*/
int op_div(int a, int b)
{
if (b == 0)
{
printf("Error\n");
exit(100);
}
return (a / b);
}
/**
* op_mod - returns remainder of division of two integers.
* @a: dividend
* @b: divisor
* Return: remainder of the division. I00
*/
int op_mod(int a, int b)
{
if (b == 0)
{
printf("Error\n");
exit(100);
}
return (a % b);
}
