#include "main.h"

/**
* test_isalpha - Checks for an alphabetic character.
* @c: The character to be checked.
*
* Return: 1 if the character is a letter, lowercase or uppercase, 0 otherwise.
*/
int test_isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

