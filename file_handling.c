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
/**
 * display_str_element - Displays the string element of a stringnode_t linked list
 * @my_h: A pointer to the first node in the list
 *
 * Return: The total number of nodes in the list (size of list)
 */
size_t display_str_element(const stringnode_t *my_h)
{
    size_t size_of_list = 0;

    for (; my_h; my_h = (*my_h).next, size_of_list++)
    {
        if ((*my_h).str)
        {
            my_puts((*my_h).str);
        }
        else
        {
            my_puts("(nil)");
        }
        my_puts("\n");
    }

    return (size_of_list);
}
/**
 * g_h_f - A function that gets the files' history
 * @d: The structure parameter 
 *
 * Return: The file history addr contained as an allocated str
 */
char *g_h_f(data_t *d)
{
    char *tmp_dir, *my_buff;

    tmp_dir = est_env_val(d, "HOME=");
    if (!tmp_dir)
        return (NULL);

    my_buff = malloc(sizeof(char) * (str_len(tmp_dir) + str_len(HIST_FILE) + 2));
    if (my_buff == NULL)
        return (NULL);

    *(my_buff + 0) = 0;  /* Equivalent to buf[0] = 0 */
    str_cpy(my_buff, tmp_dir);
    str_cat(my_buff, "/");
    str_cat(my_buff, HIST_FILE);

    return (my_buff);
}
