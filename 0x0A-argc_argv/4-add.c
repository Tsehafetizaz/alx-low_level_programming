#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
* main - Entry point, adds positive numbers
* @argc: The number of command-line arguments
* @argv: Array containing the program command line arguments
* Return: 0 if all numbers are positive, 1 otherwise
*/
int main(int argc, char *argv[])
{
int i, j, sum = 0;

for (i = 1; i < argc; i++)
{
for (j = 0; argv[i][j]; j++)
{
/* If argv[i][j] is a non-digit symbol, print error and return */
if (!isdigit(argv[i][j]))
{
printf("Error\n");
return (1);
}
}

/* Add the integer value of argv[i] to sum */
sum += atoi(argv[i]);
}

/* Print the sum */
printf("%d\n", sum);

return (0);
}
