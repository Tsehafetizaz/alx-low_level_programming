#include "main.h"

/**
* main - prints _putchar, followed by a new line
* Return: Always 0 (Success)
*/
int main(void)
{
char *s = "_putchar\n";
while (*s)
_putchar(*s++);
return (0);
}
