#include "lists.h"

/**
 * pop_listint - deletes the head node
 * @head: pointer to pointer of first node
 *
 * Return: head node data, or 0 if empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int value;

	if (head == NULL || *head == NULL)
		return (0);

	temp = *head;
	value = temp->n;

	*head = temp->next;

	free(temp);

	return (value);
}
