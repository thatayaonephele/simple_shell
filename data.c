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
	stringnode_t *current_his, *next_his;

	if (!data)
		return;

	if (x)
	{
		free(data->arg);
		free(data->argv);
		free(data->cmd_path);
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
/**
 * clear_d - A function that initializes the data_t structure
 * @d: The struct parameter addr location
 */
void clear_d(data_t *d)
{
        (*d).arg = NULL;
        (*d).argv = NULL;
        (*d).cmd_path = NULL;
        (*d).argc = 0;
}
/**
 **_str_ncpy -A function that duplicates a string
 *@end: the destination string to be copied to
 *@start: the source string
 *@chr_amount: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_str_ncpy(char *end, char *start, int chr_amount)
{
        int x = 0, y;
        char *conc_str = end;

        for (x = 0; start[x] != '\0' && x < chr_amount - 1; x++)
        {
                end[x] = start[x];
        }
        if (x < chr_amount)
        {
                for (y = x; y < chr_amount; y++)
                {
                        end[y] = '\0';
                }
        }
        return (conc_str);
}
