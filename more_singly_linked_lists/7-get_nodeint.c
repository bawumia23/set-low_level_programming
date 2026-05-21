#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node
 * @head: pointer to first node
 * @index: index of node starting from 0
 *
 * Return: pointer to node or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (head != NULL)
	{
		if (count == index)
			return (head);

		count++;
		head = head->next;
	}

	return (NULL);
}
