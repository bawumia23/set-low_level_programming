#include "hash_tables.h"
#include <string.h>

/**
 * update_existing_key - Updates the value of an existing key in a hash
 * table's collision list, if present
 * @ht: The hash table to search
 * @key: The key to search for
 * @value_copy: A heap-allocated copy of the new value
 *
 * Return: 1 if the key was found and updated, 0 if not found
 */
static int update_existing_key(hash_table_t *ht, const char *key,
		char *value_copy)
{
	unsigned long int index;
	hash_node_t *tmp;

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->next;
	}

	return (0);
}

/**
 * hash_table_set - Adds an element to a hash table
 * @ht: The hash table you want to add or update the key/value to
 * @key: The key. Cannot be an empty string
 * @value: The value associated with key. Must be duplicated.
 * Can be an empty string
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *new_node;
	char *value_copy;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_copy = strdup(value);
	if (value_copy == NULL)
		return (0);

	if (update_existing_key(ht, key, value_copy))
		return (1);

	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(value_copy);
		return (0);
	}

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(value_copy);
		free(new_node);
		return (0);
	}

	index = key_index((const unsigned char *)key, ht->size);
	new_node->value = value_copy;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
