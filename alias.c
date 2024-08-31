#include "shell.h"

/**
 * display_alias - A function that prints the alias
 * @my_node: The linked list node belonging to the alias
 * Return: 0 on success print, 1 on failed display
 */

int display_alias(stringnode_t *my_node)
{

        char *x = NULL, *ptr = NULL;

        if (my_node != NULL)
        {
                ptr = _str_chr((*my_node).str, '=');
                
                x = (*my_node).str;
                while (x <= ptr)
                {
                        _putchar(*x);
                        x++;
                }
                _putchar('\'');
                my_puts(ptr + 1);
                my_puts("'\n");
                return (0);
        }
        return (1);
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
	stringnode_t *new_alias;
	stringnode_t *current;
	char *dup_s;

	if (d == NULL)
	{
		return (1);
	}
	if (s == NULL)
	{
		return (1);
	}
	new_alias = (stringnode_t *)malloc(sizeof(stringnode_t));
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
	stringnode_t *curr;
	stringnode_t *prev;

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
