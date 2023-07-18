#include "main.h"

/* 
*print alphabet - prints the alphabet in lowercase.
*/

void print_alphabet(void)
{
char letter;
for (letter = 'a'; letter <= 'z'; letter++)
{
_putchar(letter);
}
_putchar('\n');
}

/*
*print alphabet - prints the alphabet in 10X lowercase.
*/

void print_alphabet_x10(void)
{
int i;
for (i = 0; i < 10; i++)
{
print_alphabet();
}
}

int main(void)
{
print_alphabet_x10();
}
