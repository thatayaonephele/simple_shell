#include "shell.h"
/**
 * free_data - A function that frees the data_t structure fields
 * @x: A function that acts as a boolean that frees all fields of the structure
 * @data: The variable address of the data structure
 *
 * Return: void
 */

void free_data(data_t *data, int x)
{
	linked_str *current_his, *next_his;

	if (!data)
		return;

	if (x)
	{
		free(data->arg);
		free(data->argv);
		free(data->path);
		free(data->file_name);
		free(data->_env);
	}
	current_his = data->node_his;

	while (current_his)
	{
		next_his = current_his->next;
		free(current_his->s);
		free(current_his);
		current_his = next_his;
	}
	free(data);
}
