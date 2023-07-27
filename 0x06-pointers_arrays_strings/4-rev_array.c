/**
* reverse_array - a function that reverses the content of an array of integers
* @a: the array to reverse
* @n: the number of elements in the array
*
* Return: Nothing.
*/
void reverse_array(int *a, int n)
{
int i = 0;
int temp = 0;

for (i = 0; i < n / 2; i++)
{
temp = a[i];
a[i] = a[n - i - 1];
a[n - i - 1] = temp;
}
}
