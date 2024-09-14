#include "shell.h"

/**
 * unset_my_env - Remove an enviroment variable
 * @d: The variable address of the data structure parameter
 *
 * Return: 0 on success removal, 1 on failure
 */
int unset_my_env(data_t *d)
{
    int x;

    if ((*d).argc == 1)
    {
        error_puts("Too few arguments.\n");
        return (1);
    }
    x = 1;
    while (x <= (*d).argc)
    {
        del_env(d, (*d).argv[x]);
        x++;
    }

    return (0);
}
/**
 * append_env_list - Appends vars to a linked list of env
 * @d: The variable address of the data structure parameter
 * Return: Always Success (0)
 */
int append_env_list(data_t *d)
{
    size_t x;
    stringnode_t *my_node = NULL;

    x = 0;

    while (environ[x])
    {
        append_node_end(&my_node, environ[x], 0);
        x++;
    }

    (*d)._env = my_node;
    return (0);
}
/**
 * set_my_env - Initialize or modify a variable environment
 * @d: The variable address of the data structure parameter
 *
 * Return: 0 on success, else 1 on error
 */
int set_my_env(data_t *d)
{
    if ((*d).argc != 3)
    {
        error_puts("Incorrect number of arguments\n");
        return (1);
    }
    if (add_env(d, (*d).argv[1], (*d).argv[2]))
        return (0);
    return (1);
}
/**
 * current_env - Displays the environment of the current directory
 * @d: parameter struct
 * Return: Always (0)
 */
int current_env(data_t *d)
{
        display_str_element((*d)._env);
        return (0);
}
/**
 * est_env_val - gets the value of an environment variable
 * @d: The parameter struct
 * @my_str: Name of the environment variable
 *
 * Return: the value
 */
char *est_env_val(data_t *d, const char *my_str)
{
    char *ptr;
    stringnode_t *my_node = (*d)._env;

    while (my_node != NULL)
    {
        ptr = hay_start((*my_node).str, my_str);
        if (ptr && *ptr)
            return (ptr);
        my_node = (*my_node).next;
    }
    return (NULL);
}
/**
 * w_his -A function that creates an unexisting file, or appends to it
 * @d: the parameter struct
 * Return: 1 on success, else -1 on failure
 */
int w_his(data_t *d)
{
    ssize_t file_des;
    char *n_o_f = g_h_f(d);
    stringnode_t *my_node = NULL;

    if (n_o_f == NULL)
        return (-1);

    file_des = open(n_o_f, O_CREAT | O_TRUNC | O_RDWR, 0644);
    free(n_o_f);
    if (file_des == -1)
        return (-1);

    for (my_node = (*d).history; my_node; my_node = (*my_node).next)
    {
        fd_puts((*my_node).str, file_des);
        fd_put('\n', file_des);
    }

    fd_put(BUF_FLUSH, file_des);
    close(file_des);
    return (1);
}
