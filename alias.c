#include "shell.h"

/**
 * display_alias - A function that prints the alias
 * @ll_node: The linked list node belonging to the alias
 * Return: 0 on success print, 1 on failed display
 */

int display_alias(linked_str *ll_node)
{
	int file_des = STDOUT_FILENO;

	while (ll_node != NULL)
	{
		write(file_des, "Alias: ", 7);
		write(file_des, ll_node->s, str_len(ll_node->s));
		write(file_des, "\n", 1);
		ll_node = ll_node->next;
	}
	return (0);
}
