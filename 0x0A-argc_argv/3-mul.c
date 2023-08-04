#include <stdio.h>
#include <stdlib.h>

/**
* main - Entry point
* @argc: The number of command-line arguments
* @argv: Array containing the program command line arguments
* Return: 0 - Success, or 1 if the program does not receive two arguments
*/
int main(int argc, char *argv[])
{
int num1, num2;

/* If we don't receive exactly two arguments, print error and return 1 */
if (argc != 3)
{
printf("Error\n");
return (1);
}

/* Convert arguments to integers and multiply */
num1 = atoi(argv[1]);
num2 = atoi(argv[2]);

/* Print the result */
printf("%d\n", num1 *num2);

return (0);
}
