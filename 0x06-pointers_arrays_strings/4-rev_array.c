#include <stdio.h>
/*
*reverse_array(int *a, int n) reverses array in the function 
*
*/
void reverse_array(int *a, int n) 
{
int start = 0;
int end = n - 1;
while (start < end)
{
int temp = a[start];
a[start] = a[end];
a[end] = temp;
start++;
end--;
}
}

void print_array(int *a, int n)
{
int i;
for(i = 0; i < n; i++)
{
printf("%d ", a[i]);
}
printf("\n");
}

int main()
{
int a[] = {1, 2, 3, 4, 5};
int n = sizeof(a)/sizeof(a[0]);

printf("Original array: ");
print_array(a, n);

reverse_array(a, n);

printf("Reversed array: ");
print_array(a, n);

return 0;
}

