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
/**
 * add_alias - A function that attaches the alias functionality to a string
 * @d: The variable address of the data structure parameter
 * @s: The string parameter of the alias pointer address
 *
 * Return: 0 if the attachment was successful, else 1 for failure
 */

int add_alias(data_t *d, char *s)
{
	linked_str *new_alias;
	linked_str *current;
	char *dup_s;

	if (d == NULL)
	{
		return (1);
	}
	if (s == NULL)
	{
		return (1);
	}
	new_alias = (linked_str *)malloc(sizeof(linked_str));
	if (new_alias == NULL)
	{
		return (1);
	}
	dup_s = char_dup(s, 0, str_len(s) - 1);
	if (dup_s == NULL)
	{
		free(new_alias);
		return (1);
	}
	new_alias->s = dup_s;
	new_alias->next = NULL;

	if (d->my_alias == NULL)
	{
		d->my_alias = new_alias;
	}
	else
	{
		current = d->my_alias;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_alias;
	}
	return (0);
}
/**
 * del_alias - A function that detaches the alias functionality to a string
 * @d: The variable address of the data structure parameter
 * @s: The string parameter of the alias pointer address
 *
 * Return: 0 if the detachment was successful, else 1 for failure
 */

int del_alias(data_t *d, char *s)
{
	linked_str *curr;
	linked_str *prev;

	if (d == NULL)
	{
		return (1);
	}
	if (s == NULL)
	{
		return (1);
	}

	curr = d->my_alias;
	prev = NULL;

	while (curr != NULL)
	{
		if (lexi_cmp(curr->s, s) == 0)
		{
			if (prev != NULL)
			{
				prev->next = curr->next;
			}
			else
			{
				d->my_alias = curr->next;
			}
			free(curr->s);
			free(curr);
			return (0);
		}
		prev = curr;
		curr = curr->next;
	}
	return (1);
}
