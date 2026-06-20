#include "hash_tables.h"
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - Creates a sorted hash table
 * @size: The size of the array
 *
 * Return: A pointer to the newly created sorted hash table, or NULL
 * on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * make_snode - Allocates and fills a new sorted hash node
 * @key: The key. Will be duplicated
 * @value: The value. Will be duplicated
 *
 * Return: A pointer to the new node, or NULL on failure
 */
static shash_node_t *make_snode(const char *key, const char *value)
{
	shash_node_t *new_node;

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}

	new_node->next = NULL;
	new_node->sprev = NULL;
	new_node->snext = NULL;

	return (new_node);
}

/**
 * insert_sorted - Inserts a node into the sorted (by key) linked list
 * of a sorted hash table
 * @ht: The sorted hash table
 * @new_node: The node to insert
 */
static void insert_sorted(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *tmp;

	tmp = ht->shead;
	while (tmp != NULL && strcmp(tmp->key, new_node->key) < 0)
		tmp = tmp->snext;

	if (tmp == NULL)
	{
		new_node->sprev = ht->stail;
		new_node->snext = NULL;
		if (ht->stail != NULL)
			ht->stail->snext = new_node;
		else
			ht->shead = new_node;
		ht->stail = new_node;
		return;
	}

	new_node->snext = tmp;
	new_node->sprev = tmp->sprev;
	if (tmp->sprev != NULL)
		tmp->sprev->snext = new_node;
	else
		ht->shead = new_node;
	tmp->sprev = new_node;
}

/**
 * update_skey - Updates the value of an existing key in a sorted
 * hash table, if present
 * @ht: The sorted hash table to search
 * @key: The key to search for
 * @value: The new value to set
 *
 * Return: 1 if the key was found and updated, 0 if not found
 */
static int update_skey(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *tmp;
	char *value_copy;

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			value_copy = strdup(value);
			if (value_copy == NULL)
				return (0);
			free(tmp->value);
			tmp->value = value_copy;
			return (1);
		}
		tmp = tmp->next;
	}

	return (0);
}

/**
 * shash_table_set - Adds an element to a sorted hash table
 * @ht: The sorted hash table you want to add or update the key/value to
 * @key: The key. Cannot be an empty string
 * @value: The value associated with key. Must be duplicated.
 * Can be an empty string
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	if (update_skey(ht, key, value))
		return (1);

	new_node = make_snode(key, value);
	if (new_node == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	insert_sorted(ht, new_node);

	return (1);
}

/**
 * shash_table_get - Retrieves a value associated with a key in a
 * sorted hash table
 * @ht: The sorted hash table you want to look into
 * @key: The key you are looking for
 *
 * Return: The value associated with the element, or NULL if key
 * couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);

	tmp = ht->array[index];
	while (tmp != NULL)
	{
		if (strcmp(tmp->key, key) == 0)
			return (tmp->value);
		tmp = tmp->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table using the sorted
 * linked list
 * @ht: The sorted hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int first;

	if (ht == NULL)
		return;

	first = 1;
	printf("{");
	for (node = ht->shead; node != NULL; node = node->snext)
	{
		if (first == 0)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		first = 0;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order,
 * using the sorted linked list
 * @ht: The sorted hash table to print
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int first;

	if (ht == NULL)
		return;

	first = 1;
	printf("{");
	for (node = ht->stail; node != NULL; node = node->sprev)
	{
		if (first == 0)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		first = 0;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table
 * @ht: The sorted hash table to delete
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node != NULL)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(ht->array);
	free(ht);
}
