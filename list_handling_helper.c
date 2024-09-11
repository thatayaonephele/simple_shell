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
