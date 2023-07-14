#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * This program generates a random number, stores it in the variable 'n',
 * and then prints the last digit of 'n' along with additional information
 * based on the value of the last digit.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int n;

srand(time(0)); // Seed the random number generator with current time
n = rand() - RAND_MAX / 2; // Generate a random number

printf("Last digit of %d is %d", n, n % 10); // Print the last digit of n

if (n % 10 > 5)
printf(" and is greater than 5\n"); // Additional information for last digit > 5
else if (n % 10 == 0)
printf(" and is 0\n"); // Additional information for last digit = 0
else
printf(" and is less than 6 and not 0\n"); // Additional information for last digit < 6 and not 0

return (0);
}

