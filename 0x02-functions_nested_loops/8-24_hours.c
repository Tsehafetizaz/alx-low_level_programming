#include "main.h"

/**
* jack_bauer-  prints every minute of the day of Jack Bauer
* @n: The number to be checked
*
* Return: 1 if the number is greater than zero, 0 if the number is zero,
*         -1 if the number is less than zero.
*/
void jack_bauer(void)
{
int hour;
int minute;

for (hour = 0; hour < 24; hour++)
{
for (minute = 0; minute < 60; minute++)
{
_putchar((hour / 10) + '0');
_putchar((hour % 10) + '0');
_putchar(':');
_putchar((minute / 10) + '0');
_putchar((minute % 10) + '0');
_putchar('\n');
}
}
}
