#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at index index
 * @head: double pointer to the start of the list
 * @index: index of the node that should be deleted, starting at 0
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *temp;
listint_t *next_node;
unsigned int i;

if (head == NULL || *head == NULL)
return (-1);
temp = *head;

if (index == 0)
{
*head = temp->next;
free(temp);
return (1);
}

for (i = 1; i < index; i++)
{
if (temp == NULL || temp->next == NULL)
return (-1);
temp = temp->next;
}
next_node = temp->next->next;
free(temp->next);
temp->next = next_node;
return (1);
}
