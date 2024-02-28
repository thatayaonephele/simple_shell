#include "shell.h"

/**
 * display_list - Displays all elements stored in the linked_str list
 * @head_node: A pointer pointing to the address of the 1st Linked list node
 * Return: Linked List size
 */

size_t display_list(const linked_str *head_node)
{
	size_t x = 0;

	while ((!head_node) == false)
	{
		my_puts(num_converter(head_node->n, 10, 0));
		_putchar(':');
		_putchar(' ');
		if (!(head_node->s) == true)
			my_puts("(nil)");
		else
			my_puts(head_node->s);

		my_puts("\n");
		head_node = head_node->next; /**head node becomes the next node on list*/
		x++;
	}
	return (x);
}
