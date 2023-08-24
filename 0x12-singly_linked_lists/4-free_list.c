#include "lists.h"
#include <stdlib.h>

/**
* free_list - Frees a list_t list.
* @head: pointer to the start of the linked list.
* Return: void.
*/
void free_list(list_t *head)
{
list_t *temp;

while (head != NULL)
{
temp = head;
head = head->next;
free(temp->str);
free(temp);
}
}

