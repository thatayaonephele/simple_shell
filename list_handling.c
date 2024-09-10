#include "shell.h"

/**
 * get_list_len - determines length of linked list
 * @head_node: pointer to first node
 *
 * Return: size of list
 */
size_t get_list_len(const stringnode_t *head_node)
{
    size_t x = 0;

    for (; head_node != NULL; head_node = (*head_node).next)
    {
        x++;
    }
    return (x);
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
 * @head_ptr: A pointer to the address of the 1st linked list node
 *
 * Return: Nothing (void)
 */
void free_mem(stringnode_t **head_ptr)
{
    stringnode_t *my_node, *next_node, *head;

    if (!head_ptr || !*head_ptr)
        return;

    head = *head_ptr;
    my_node = head;
    for (; my_node; my_node = next_node)
    {
        next_node = (*my_node).next;
        free((*my_node).str);
        free(my_node);
    }
    *head_ptr = NULL;
}

/**
 * d_n_a_i - A function that deletes a node at a specified position
 * @head: The pointer address parameter to the 1st node 
 * @j: index position of node to be deleted
 *
 * Return: 1 on success, 0 on failure
 */
int d_n_a_i(stringnode_t **head, unsigned int j)
{
    stringnode_t *my_node, *prev_node;
    unsigned int x = 0;

    if (!head || *head == NULL)
        return (0);

    if (!j)
    {
        my_node = *head;
        *head = (*(*head)).next;
        free((*my_node).str);
        free(my_node);
        return (1);
    }

    my_node = *head;
    for (; my_node; my_node = (*my_node).next)
    {
        if (x == j)
        {
            (*prev_node).next = (*my_node).next;
            free((*my_node).str);
            free(my_node);
            return (1);
        }
        x++;
        prev_node = my_node;
    }
    return (0);
}
