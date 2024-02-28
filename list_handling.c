#include "shell.h"

/**
 * get_list_len - Gets the linked list length
 * @head_node: A pointer pointing to the address of the 1st linked list node
 *
 * Return: linked list size
 */

size_t get_list_len(const linked_str *head_node)
{
	size_t count;
	const linked_str *current_node;

	count = 0;

	/*traverse the linked list & count nodes*/
	current_node = head_node;

	while (current_node != NULL)
	{
		count++;
		current_node = current_node->next;
	}
	return (count);
}
