#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to the head of the list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
size_t i;
const listint_t *current = head;
const listint_t *array[1024];

while (current)
{
printf("[%p] %d\n", (void *)current, current->n);
array[count] = current;
count++;

current = current->next;

for (i = 0; i < count - 1; i++)
{
if (array[i] == current)
{
printf("-> [%p] %d\n", (void *)current, current->n);
return (count);
}
}
}

return (count);
}
