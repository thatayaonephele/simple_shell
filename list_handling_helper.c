#include "shell.h"
/**
 * free_str_array - function to free the allocated memory for the array
 * of strings
 * @str_array: strings memory to free
 */
void free_str_array(char **str_array)
{
    char **temp = str_array;

    if (str_array == NULL)
        return;

    for (; **str_array; str_array++)
        free(*str_array);

    free(temp);
}
/**
 * free_data - A function that frees the data_t structure fields
 * @x: A function that acts as a boolean that frees all fields of the structure
 * @data: The variable address of the data structure
 *
 * Return: void
 */
void free_data(data_t *d, int x)
{
    str_free((*d).argv);
    (*d).argv = NULL;
    (*d).cmd_path = NULL;
    if (x)
    {
        if (!(*d).cmd_buf)
            free((*d).arg);
        if ((*d)._env)
            free_mem(&(*d)._env);
        if ((*d).my_his)
            free_mem(&(*d).my_his);
        if ((*d).alias)
            free_mem(&(*d).alias);
        str_free((*d).environ);
        (*d).environ = NULL;
        free_vars((void **)(*d).cmd_buf);
        if ((*d).r_fd > 2)
            close((*d).r_fd);
        _putchar(BUF_FLUSH);
    }
}
