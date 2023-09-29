/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: The binary string to be converted.
 * Return: The converted unsigned int value of the binary string.
 */
unsigned int binary_to_uint(const char *b)
{
unsigned int num = 0;

if (!b)
return (0);

while (*b)
{
if (*b != '0' && *b != '1')
return (0);

num = (num << 1) + (*b++ - '0');
}
return (num);
}
