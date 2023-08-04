#include <stdio.h>

/**
* main - Entry point of the program
*
* Description: Prints the alphabet in lowercase.
* Uses the putchar function.
* Outputs the alphabet followed by a new line.
*
* Return: Always 0 (Success)
*/
int main(void)
{
char letter;

for (letter = 'a'; letter <= 'z'; letter++)
{
putchar(letter);
}

putchar('\n');

return (0);
}

