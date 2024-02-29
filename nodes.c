#include "shell.h"

/**
 *find_index_node - A function that determines the linked list node index
 *@h: The pointer pointing to node of linked List head address
 *@my_node: The pointer pointing to node of the linked List address
 *Return: The node index if successful,else -1 if unsuccessful
 */

ssize_t find_index_node(stringnode_t *h, stringnode_t *my_node)
{
	size_t x = 0;

	for (; h != NULL; x++)
	{
		if (h == my_node) /*search for a head and node match*/
			return (x); /*if match found thats the index*/
		h = h->next; /*next index pos becomes the head*/
	}
	return (-1);
}
/**
 * node_starts_with - Return a node based on  a desired sub str matching prefix
 * @my_node: The ptr pointing to the head of the linked list
 * @sub_str: The desired matching search string
 * @chr: The preceeding char after matching is completed
 * Return: The macthed my_node ptr on success, else null
 */

stringnode_t *node_starts_with(stringnode_t *my_node, char *sub_str, char chr)
{
	char *ptr = NULL;

	for (; my_node; my_node = my_node->next)
	{
		ptr = hay_start(my_node->s, sub_str);
		if (ptr && chr == -1)
			return (my_node);
		if (*ptr == chr)
			return (my_node);
	}
	return (NULL);
}
/**
 * add_node - Appends to the linked list start index a new node
 * @node_h: The pointer pointing to node of the linked List head address
 * @s: The struct string field variable of the linked list node
 * @n: The struct field number for the shell history index node
 *
 * Return: The linked list size on success,else NULL on failuire
 */
stringnode_t *add_node(stringnode_t **node_h, char *s, int n)
{
	stringnode_t *new_node, *current;

	new_node = (stringnode_t *)malloc(sizeof(stringnode_t));
	if (new_node == NULL)
		return (NULL);

	new_node->s = _str_ncpy(NULL, s, str_len(s));
	new_node->n = n;
	new_node->next = NULL;

	if (*node_h == NULL)
	{
		*node_h = new_node;
		return (new_node);
	}
	current = *node_h;
	while (current->next != NULL)
		current = current->next;

	current->next = new_node;

	return (new_node);
}
