#include "shell.h"

/**
 * get_list_len - Gets the linked list length
 * @head_node: A pointer pointing to the address of the 1st linked list node
 *
 * Return: linked list size
 */

size_t get_list_len(const stringnode_t *head_node)
{
	size_t count;
	const stringnode_t *current_node;

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
/**
 * list_to_str - Prints input list as an array of stringed chars
 * @my_head: A pointer to the address of the first linked list nodde
 *
 * Return: An array of stringed characters
 */

char **list_to_str(stringnode_t *my_head)
{
	int num_nodes = 0;
	int i;
	stringnode_t *current_node = my_head;
	char **str_array;

	while (current_node != NULL)
	{
		num_nodes++;
		current_node = current_node->next;
	}
	str_array = (char **)malloc((num_nodes + 1) * sizeof(char *));
	if (str_array == NULL)
	{
		perror("malloc");
		_exit(EXIT_FAILURE);
	}

	current_node = my_head;
	i = 0;

	while (current_node != NULL)
	{
		str_array[i] = current_node->s;
		current_node = current_node->next;
		i++;
	}
	str_array[num_nodes] = NULL;

	return (str_array);
}
/**
 * free_mem - A function that frees the allocated memory of all LL nodes
 * @h: A pointer to the address of the 1st linked list node
 *
 * Return: Nothing (void)
 */

void free_mem(stringnode_t **h)
{
	stringnode_t *current = *h;
	stringnode_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current->s);
		free(current);
		current = next;
	}
	*h = NULL;
}
