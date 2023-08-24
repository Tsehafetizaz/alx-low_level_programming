#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
* create_node - creates a new node for a list_t linked list.
* @str: string to put in the new node.
* Return: pointer to the new node, or NULL if failed.
*/
list_t *create_node(const char *str)
{
list_t *new_node;
unsigned int len = strlen(str);

new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);

new_node->str = strdup(str);
if (!(new_node->str))
{
free(new_node);
return (NULL);
}
new_node->len = len;
new_node->next = NULL;

return (new_node);
}
