#include <stdio.h>

/**
* main - Entry point
* @argc: The number of command-line arguments
* @argv: Array containing the program command line arguments (unused)
* Return: 0 - Success
*/
int main(int argc, char *argv[])
{
(void) argv; /* Suppress unused variable warning */
printf("%d\n", argc - 1); /* Subtract 1 to exclude the program name */
return (0);
}
