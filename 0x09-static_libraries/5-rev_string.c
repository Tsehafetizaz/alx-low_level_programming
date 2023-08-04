#include "main.h"

/**
* rev_string - Reverses a string
* @s: String to be reversed
*
* Return: void
*/
void rev_string(char *s)
{
int length = 0;
int i;
char temp;

while (s[length] != '\0') /* find the length of the string */
{
length++;
}
/* swap characters at mirrored positions */
for (i = 0; i < length / 2; i++)
{
temp = s[i];
s[i] = s[length - 1 - i];
s[length - 1 - i] = temp;
}
}

