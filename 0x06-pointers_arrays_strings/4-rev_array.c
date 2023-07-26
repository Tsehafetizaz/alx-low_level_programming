#include "main.h"

/**
 * reverse_array - a function that reverses the content of an array of integers
 * @a: array of integers to be reversed
 * @n: the number of elements in the array
 *
 * Return: void
 */
void reverse_array(int *a, int n)
{
int tmp, i;
for(i = 0; i < n / 2; i++)
{
tmp = a[i];
a[i] = a[n - 1 - i];
a[n - 1 - i] = tmp;
}
}
