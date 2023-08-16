#include "function_pointers.h"

/**
* array_iterator - Executes a function given as a parameter on
* each element of an array.
* @array: Pointer to the array of integers
* @size: Size of the array
* @action: Pointer to the function you need to use
*/
void array_iterator(int *array, size_t size, void (*action)(int))
{
size_t i;

if (array == NULL || action == NULL)
return;

for (i = 0; i < size; i++)
action(array[i]);
}
