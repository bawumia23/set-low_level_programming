#include "lists.h"
#include <stdlib.h>

/**
 * print_addr - prints a memory address using _putchar
 * @addr: the address to print
 */
static void print_addr(unsigned long addr)
{
	char hex[16];
	int hlen = 0;
	const char *digits = "0123456789abcdef";
	int j;

	_putchar('0');
	_putchar('x');
	while (addr)
	{
		hex[hlen++] = digits[addr % 16];
		addr /= 16;
	}
	for (j = hlen - 1; j >= 0; j--)
		_putchar(hex[j]);
}

/**
 * print_num - prints an integer using _putchar
 * @n: the integer to print
 */
static void print_num(int n)
{
	char buf[12];
	int len = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	if (n == 0)
		buf[len++] = '0';
	while (n > 0)
	{
		buf[len++] = '0' + (n % 10);
		n /= 10;
	}
	while (len--)
		_putchar(buf[len]);
}

/**
 * print_node - prints a single node
 * @node: the node to print
 */
static void print_node(const listint_t *node)
{
	_putchar('[');
	print_addr((unsigned long)node);
	_putchar(']');
	_putchar(' ');
	print_num(node->n);
	_putchar('\n');
}

/**
 * is_visited - checks if a node was already visited
 * @visited: array of visited nodes
 * @count: number of nodes visited
 * @node: node to check
 *
 * Return: 1 if visited, 0 otherwise
 */
static int is_visited(const listint_t **visited,
		size_t count, const listint_t *node)
{
	size_t i;

	for (i = 0; i < count; i++)
	{
		if (visited[i] == node)
			return (1);
	}
	return (0);
}

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count;
	size_t size;
	size_t i;
	const listint_t **visited;
	const listint_t **new_v;
	const listint_t *tmp;

	if (head == NULL)
		return (0);
	size = 1024;
	visited = malloc(sizeof(listint_t *) * size);
	if (visited == NULL)
		exit(98);
	count = 0;
	tmp = head;
	while (tmp != NULL)
	{
		if (is_visited(visited, count, tmp))
		{
			_putchar('-');
			_putchar('>');
			_putchar(' ');
			print_node(tmp);
			free(visited);
			return (count);
		}
		if (count >= size)
		{
			size *= 2;
			new_v = malloc(sizeof(listint_t *) * size);
			if (new_v == NULL)
				exit(98);
			for (i = 0; i < count; i++)
				new_v[i] = visited[i];
			free(visited);
			visited = new_v;
		}
		visited[count++] = tmp;
		print_node(tmp);
		tmp = tmp->next;
	}
	free(visited);
	return (count);
}
