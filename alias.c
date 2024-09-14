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
int add_alias(data_t *d, char *str)
{
        char *ptr;

        ptr = str_chr(str, '=');
        if (ptr == NULL)
                return (1);
        if (*++ptr == NULL)
                return (del_alias(d, str));

        del_alias(d, str);
        return (app_node_end(&((*d).my_alias), str, 0) == NULL);
}
/**
 * del_alias - A function that detaches the alias functionality to a string
 * @d: The variable address of the data structure parameter
 * @str: The string parameter of the alias pointer address
 *
 * Return: 0 if the detachment was successful, else 1 for failure
 */
int del_alias(data_t *d, char *str)
{

    int result;
    char *ptr;
    char chr;

    ptr = str_chr(str, '=');
    if (ptr == NULL)
        return (1);

    chr = *ptr;
    *ptr = 0;

    result = d_n_a_i(&((*d).my_alias),
                g_n_i((*d).my_alias, n_s_w((*d).my_alias, str, -1)));

    *ptr = chr;
    return (result);
}
