#include "shell.h"

/**
 *find_index_node - A function that determines the linked list node index
 *@h: The pointer pointing to node of linked List head address
 *@my_node: The pointer pointing to node of the linked List address
 *Return: The node index if successful,else -1 if unsuccessful
 */

ssize_t find_index_node(linked_str *h, linked_str *my_node)
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
