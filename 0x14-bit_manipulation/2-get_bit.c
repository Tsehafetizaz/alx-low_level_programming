/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: The number to get the bit value from.
 * @index: The index of the bit.
 * Return: The value of the bit at the given index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
if (index > (sizeof(n) * 8))
return (-1);

return ((n >> index) & 1);
}
