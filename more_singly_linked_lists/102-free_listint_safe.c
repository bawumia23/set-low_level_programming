#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a listint_t linked list safely
 * @h: pointer to pointer to the head of the list
 *
 * Return: size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *slow;
	listint_t *fast;
	listint_t *tmp;
	size_t count;

	if (h == NULL || *h == NULL)
		return (0);

	slow = *h;
	fast = *h;
	count = 0;

	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow->next = NULL;
			break;
		}
	}

	while (*h != NULL)
	{
		tmp = (*h)->next;
		free(*h);
		*h = tmp;
		count++;
	}

	*h = NULL;
	return (count);
}
