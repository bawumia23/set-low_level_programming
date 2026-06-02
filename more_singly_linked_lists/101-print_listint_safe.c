#include "lists.h"
#include <stdlib.h>

#define MAX_NODES 1024

/**
 * print_addr - prints a memory address using _putchar
 * @addr: address to print
 */
static void print_addr(unsigned long addr)
{
	char hex[16];
	int i = 0, j;
	const char *d = "0123456789abcdef";

	_putchar('0');
	_putchar('x');

	if (addr == 0)
	{
		_putchar('0');
		return;
	}

	while (addr)
	{
		hex[i++] = d[addr % 16];
		addr /= 16;
	}

	for (j = i - 1; j >= 0; j--)
		_putchar(hex[j]);
}

/**
 * print_num - prints an integer using _putchar
 * @n: integer to print
 */
static void print_num(int n)
{
	char buf[12];
	int i = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	while (n > 0)
	{
		buf[i++] = (n % 10) + '0';
		n /= 10;
	}

	while (i--)
		_putchar(buf[i]);
}

/**
 * is_visited - checks if a node was already visited
 * @visited: array of visited nodes
 * @count: number of visited nodes
 * @node: node to check
 *
 * Return: 1 if node is already visited, 0 otherwise
 */
static int is_visited(const listint_t **visited,
size_t count, const listint_t *node)
{
	size_t i;

	for (i = 0; i < count; i++)
		if (visited[i] == node)
			return (1);

	return (0);
}

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to head of list
 *
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *visited[MAX_NODES];
	size_t i = 0;

	while (head)
	{
		if (i >= MAX_NODES || is_visited(visited, i, head))
		{
			_putchar('-');
			_putchar('>');
			_putchar(' ');
			_putchar('[');
			print_addr((unsigned long)head);
			_putchar(']');
			_putchar(' ');
			print_num(head->n);
			_putchar('\n');
			return (i);
		}

		visited[i++] = head;

		_putchar('[');
		print_addr((unsigned long)head);
		_putchar(']');
		_putchar(' ');
		print_num(head->n);
		_putchar('\n');

		head = head->next;
	}

	return (i);
}
