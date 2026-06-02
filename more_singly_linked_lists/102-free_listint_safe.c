#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t list safely (even with loops)
 * @h: pointer to head
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	const listint_t *visited[1024];
	listint_t *tmp;
	listint_t *next;
	size_t i = 0, j;
	int loop;

	if (h == NULL)
		return (0);

	tmp = *h;

	while (tmp)
	{
		loop = 0;

		for (j = 0; j < i; j++)
		{
			if (visited[j] == tmp)
			{
				loop = 1;
				break;
			}
		}

		if (loop)
			break;

		visited[i++] = tmp;

		next = tmp->next;   /* ✅ save BEFORE free */
		free(tmp);
		tmp = next;
	}

	*h = NULL;
	return (i);
}
