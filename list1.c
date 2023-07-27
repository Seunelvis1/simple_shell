#include "shell.h"

/**
 * list_len - it checked the length of linked list
 * @b: points to the first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *b)
{
	size_t j = 0;

	while (b)
	{
		b = b->next;
		j++;
	}
	return (j);
}

/**
 * list_to_strings - it returns an array of strings
 * @head: points to the first node
 *
 * Return: strings array
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - it prints all elements of a list_t linked list
 * @h: points to the first node
 *
 * Return: size of the list
 */
size_t print_list(const list_t *h)
{
	size_t j = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		j++;
	}
	return (j);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: points to list head
 * @prefix: string to match
 * @ch: the next character to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char ch)
{
	char *q = NULL;

	while (node)
	{
		q = starts_with(node->str, prefix);
		if (q && ((ch == -1) || (*q == ch)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - it gets the index of a node
 * @head: points to list head
 * @node: points to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t j = 0;

	while (head)
	{
		if (head == node)
			return (j);
		head = head->next;
		j++;
	}
	return (-1);
}
