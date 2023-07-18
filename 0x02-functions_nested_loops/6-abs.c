#include "main.h"

/**
* _abs - computes the absolute value of an integer
* @n: The number to be checked
*
* Return: 1 if the number is greater than zero, 0 if the number is zero,
*         -1 if the number is less than zero.
*/
int _abs(int n)
{
if (n < 0)
{
return (-n);
}
else
{
return (n);
}
