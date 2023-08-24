#include "lists.h"
#include <stdio.h>

/**
* print_list - Prints all the elements of a list_t list.
* @list: pointer to the start of the linked list.
* Return: the number of nodes in the list.
*/
size_t print_list(const list_t *list)
{
size_t nodes = 0;

while (list != NULL)
{
if (list->str == NULL)
printf("[0] (nil)\n");
else
printf("[%u] %s\n", list->len, list->str);

list = list->next;
nodes++;
}
return(nodes);
}

