#include "hash_tables.h"

unsigned long int key_index(const unsigned char *key, unsigned long int size);

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array of the hash table.
 *
 * Return: A pointer to the newly created sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = malloc(sizeof(shash_table_t));

	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds or updates an element in a sorted hash table.
 * @ht: The sorted hash table you want to add or update the key/value to.
 * @key: The key. key cannot be an empty string.
 * @value: The value associated with the key.
 *
 * Return: 1 if it succeeded, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node, *new_node, *tmp;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	for (node = ht->array[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = strdup(value);
			return (1);
		}
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}

	new_node->next = ht->array[index];
	ht->array[index] = new_node;

tmp = tmp->snext);

	new_node->snext = tmp;
	new_node->sprev = tmp ? tmp->sprev : NULL;
	if (tmp && tmp->sprev)
		tmp->sprev->snext = new_node;
	else
		ht->shead = new_node;
	if (tmp)
		tmp->sprev = new_node;
	else
		ht->stail = new_node;

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated
 * @ht: The hash table you want to look into.
 * @key: The key you are looking for.
 *
 * Return: The value associated with the key, or
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node;

	if (!ht || !key)
	return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	for (node = ht->array[index]; node; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		return (node->value);
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table.
 * @ht: The sorted hash table to print.
 *
 * This function prints the key/value pairs in order by traversing
 * the sorted linked list starting from shead.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
		return;

	printf("{");
	for (node = ht->shead; node != NULL; node = node->snext)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->snext)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: The sorted hash table to print.
 *
 * This function prints the key/value pairs in reverse order by
 * traversing the sorted linked list starting from stail.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (!ht)
		return;

	printf("{");
	for (node = ht->stail; node != NULL; node = node->sprev)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->sprev)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table to delete.
 *
 * This function frees all memory used by the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *temp;
	unsigned long int i;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node != NULL)
{
			temp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = temp;
		}
	}

	free(ht->array);
	free(ht);
}
