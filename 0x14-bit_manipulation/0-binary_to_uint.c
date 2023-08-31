#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: the converted unsigned int
 * or 0 if b is NULL or there is a char that is not 0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int decimal = 0;
int base = 1;
int i = 0;
if (b == NULL)
return (0);

while (b[i + 1])
i++;

while (i >= 0)
{
if (b[i] < '0' || b[i] > '1')
return (0);

if (b[i] == '1')
decimal += base;

base *= 2;
i--;
}

return (decimal);
}
