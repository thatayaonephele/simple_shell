#include "shell.h"

/**
 * display_list - Displays all elements stored in the linked_str list
 * @head_node: A pointer pointing to the address of the 1st Linked list node
 * Return: Linked List size
 */

size_t display_list(const stringnode_t *head_node)
{
    size_t x = 0;

    for (; head_node; head_node = (*head_node).next, x++)
    {
        my_puts(num_converter((*head_node).n, 10, 0));
        _putchar(':');
        _putchar(' ');

        if ((*head_node).str)
            my_puts((*head_node).str);
        else
            my_puts("(nil)");

        my_puts("\n");
    }

    return (x);
}

/**
 * char_dup - A functin that duplicates inputed chars
 * @str_path: The parameter representing the PATH str
 * @src: The commencing index parameter
 * @dest: The ending index parameter
 * Return: The ptr pointing to the new buffer
 */
char *char_dup(char *str_path, int src, int dest)
{

    int x = 0, z = 0;
    static char my_buff[1024];

    x = src;
    while (x < dest)
    {
        if (*(str_path + x) != ':')
            *(my_buff + z++) = *(str_path + x);
        x++;
    }
    *(my_buff + z) = '\0';
    return (my_buff);
}
