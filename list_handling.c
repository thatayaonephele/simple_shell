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
 * cnv_cnv_list_to_str - Prints input list as an array of stringed chars
 * @my_head: A pointer to the address of the first linked list nodde
 *
 * Return: An array of stringed characters
 */
char **cnv_list_str(stringnode_t *my_head)
{
    stringnode_t *my_node = my_head;
    size_t x = get_list_len(my_head), y;
    char **sub_str;
    char *str;

    if (my_head == NULL || !x)
        return (NULL);

    sub_str = malloc(sizeof(char *) * (x + 1));
    if (sub_str == NULL)
        return (NULL);

    x = 0;
    while (my_node != NULL)
    {
        str = malloc(str_len((*my_node).str) + 1);
        if (str == NULL)
        {
            y = 0;
            while (y < x)
            {
                free(sub_str[y]);
                y++;
            }
            free(sub_str);
            return (NULL);
        }

        str = str_cpy(str, (*my_node).str);
        sub_str[x] = str;
        my_node = (*my_node).next;
        x++;
    }
    sub_str[x] = NULL;
    return (sub_str);
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
