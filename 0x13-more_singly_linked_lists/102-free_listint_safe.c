#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: pointer to the address of the start of the list
 * Return: the size of the list that was free'd
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *slow, *fast, *tmp;
size_t nodes = 0;

if (h == NULL || *h == NULL)
return (0);

slow = *h;
fast = *h;

while (slow != NULL && fast != NULL && fast->next != NULL)
{
nodes++;
tmp = slow;
slow = slow->next;
fast = fast->next->next;
free(tmp);

if (slow == fast)
{
*h = NULL;
return (nodes);
}
}

*h = NULL;
return (nodes);
}
