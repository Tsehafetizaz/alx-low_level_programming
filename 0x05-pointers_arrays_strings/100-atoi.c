#include <limits.h>
/**
* This function converts a string to an integer, accounting for any + or - signs before the number.
* If there are no numbers in the string, the function returns 0.
* 
* @param s The string to convert.
* @return The converted integer.
*/

int _atoi(char *s)
{
int result = 0;
int sign = 1;
int i = 0;
while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
{
if (s[i] == '-')
{
sign = sign * -1;
}
else if (s[i] == '+')
{
sign = sign * 1;
}
i++;
}
while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
{
if (result > INT_MAX / 10 ||
(result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10))
{
return ((sign == 1) ? INT_MAX : INT_MIN);
}
result = result * 10 + (s[i++] - '0');
}
return (result *sign);
}
