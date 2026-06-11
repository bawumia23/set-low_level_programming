#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

int main(void)
{
	dlistint_t *head;
	dlistint_t *new;
	size_t n;

	dlistint_t hello = {8, NULL, NULL};

	head = &hello;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (1);

	new->n = 9;
	new->prev = NULL;
	new->next = head;
	head->prev = new;
	head = new;

	n = print_dlistint(head);
	printf("-> %lu elements\n", n);

	free(new);

	return (0);
}
