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
 * find_loop - finds the node where a loop starts
 * @head: pointer to the head of the list
 *
 * Return: pointer to loop start node, or NULL
 */
static listint_t *find_loop(const listint_t *head)
{
	const listint_t *slow;
	const listint_t *fast;

	slow = head;
	fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return ((listint_t *)slow);
		}
	}
	return (NULL);
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
	const listint_t *loop_node;
	const listint_t *tmp;

	count = 0;
	loop_node = find_loop(head);
	tmp = head;
	while (tmp != NULL)
	{
		if (tmp == loop_node && count > 0)
		{
			_putchar('-');
			_putchar('>');
			_putchar(' ');
			break;
		}
		print_node(tmp);
		count++;
		tmp = tmp->next;
	}
	if (loop_node != NULL)
	{
		print_node(loop_node);
		count++;
	}
	return (count);
}
