#include "shell.h"
/**
 * free_str_array - function to free the allocated memory for the array
 * of strings
 * @str_array: strings memory to free
 */

void free_str_array(char **str_array)
{
	int i = 0;

	while (str_array[i] != NULL)
	{
		free(str_array[i]);
		i++;
	}
	free(str_array);
}
