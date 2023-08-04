#include <stdio.h>
#include <stdlib.h>

/**
* reduce_cents - reduces the amount of cents and increments coins
* @cents: pointer to the amount of cents
* @value: coin value to reduce cents
* Return: number of coins
*/
int reduce_cents(int *cents, int value)
{
int coins = 0;

while (*cents >= value)
{
*cents -= value;
coins++;
}

return (coins);
}

/**
* main - Entry point, prints minimum number of coins to make change
* @argc: The number of command-line arguments
* @argv: Array containing the program command line arguments
* Return: 0 if all numbers are positive, 1 otherwise
*/
int main(int argc, char *argv[])
{
int cents, coins = 0;

/* If the number of arguments is not exactly 1, print Error and return 1 */
if (argc != 2)
{
printf("Error\n");
return (1);
}

/* Convert argument to an integer */
cents = atoi(argv[1]);

/* If the number is negative, print 0 and return */
if (cents < 0)
{
printf("0\n");
return (0);
}

/* Subtract the largest coin value and increment coins while possible */
coins += reduce_cents(&cents, 25);
coins += reduce_cents(&cents, 10);
coins += reduce_cents(&cents, 5);
coins += reduce_cents(&cents, 2);
coins += reduce_cents(&cents, 1);

/* Print the number of coins */
printf("%d\n", coins);

return (0);
}
