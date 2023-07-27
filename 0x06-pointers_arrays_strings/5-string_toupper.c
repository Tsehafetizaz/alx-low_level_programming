#include "main.h"
/**
 * string_toupper - a function that changes all lowercase letters to uppercase
 * @s: the string to change
 *
 * Return: pointer to the string.
 */
char *string_toupper(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 'a' + 'A';
        }
        i++;
    }
    return (s);
}
