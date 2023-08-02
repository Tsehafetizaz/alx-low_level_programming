#include "main.h"

/**
* _strlen_recursion - returns the length of a string.
* @s: string to measure
* Return: integer length of string
*/
int _strlen_recursion(char *s)
{
if (*s)
return (1 + _strlen_recursion(s + 1));
else
return (0);
}

/**
* check_palindrome - checks to see if a string is a palindrome.
* @s: string to check
* @n: size of string
* @i: index to compare
* Return: 1 if string is a palindrome, 0 if not.
*/
int check_palindrome(char *s, int n, int i)
{
if (i > n / 2)
return (1);
else if (s[i] != s[n - i - 1])
return (0);
else
return (check_palindrome(s, n, i + 1));
}

/**
 * is_palindrome - states if string is a palindrome
 * @s: string to check
 * Return: 1 if string is a palindrome, 0 if not
 */
int is_palindrome(char *s)
{
if (!*s)
return (1);
return (check_palindrome(s, _strlen_recursion(s), 0));
}
