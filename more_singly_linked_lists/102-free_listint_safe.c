#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list safely (even with loops)
 * @h: pointer to head pointer
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *tmp;
	listint_t *next;

	if (h == NULL)
		return (0);

	tmp = *h;

	while (tmp)
	{
		next = tmp->next;

		free(tmp);
		count++;

		/* break if loop detected (next already freed memory case avoided by order) */
		if (next == NULL)
			break;

		tmp = next;
	}

	*h = NULL;
	return (count);
}
