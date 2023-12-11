#include <stdio.h>
#include "operations.h"
/**
 * @brief Adds two integers.
 * @param a First integer to add.
 * @param b Second integer to add.
 * @return The sum of a and b.
 */
int add(int a, int b)
{
return (a + b);
}

/**
 * @brief Subtracts two integers.
 * @param a First integer (minuend).
 * @param b Second integer (subtrahend).
 * @return The difference of a and b (a - b).
 */
int sub(int a, int b)
{
return (a - b);
}

/**
 * @brief Multiplies two integers.
 * @param a First integer to multiply.
 * @param b Second integer to multiply.
 * @return The product of a and b (a * b).
 */
int mul(int a, int b)
{
return (a * b);
}

/**
 * @brief Divides two integers.
 * @param a Numerator (dividend).
 * @param b Denominator (divisor).
 * @return The quotient of a and b (a / b),
 * or 0 if b is 0 and an error message is printed.
 */
int div(int a, int b)
{
if (b == 0)
{
printf("Error: Division by zero!\n");
return (0);
}
return (a / b);
}

/**
 * @brief Computes the modulo of two integers.
 * @param a Dividend.
 * @param b Divisor.
 * @return The remainder of a divided by b (a % b),
 * or 0 if b is 0 and an error message is printed.
 */
int mod(int a, int b)
{
if (b == 0)
{
printf("Error: Modulo by zero!\n");
return (0);
}
return (a % b);
}
