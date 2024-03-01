#include "shell.h"

/**
 * _change_dir - Returns the changes made in the current user directory
 * @d: Structure containing potential arguments. Used to maintain *
 * Return: Always Success(0)
 */
int _change_dir(data_t *d)
{
	if (d == NULL || d->cmd_path == NULL)
	{
		write(STDERR_FILENO, "Invalid data_t or path argument.\n",
				strlen("Invalid data_t or path argument.\n"));
		return (-1);
	}
	if (chdir(d->cmd_path) == -1)
	{
		char err_msg[] = "chdir: Error chnaging directory\n";

		write(STDERR_FILENO, err_msg, strlen(err_msg));
		return (-1);
	}
	return (0);
}
/**
 * current_cd - Returns change made in a process's directory
 * @d: The variable address of the data structure parameter
 *
 * Return: 0 on Success, else 1 is on failure
 */

int current_cd(data_t *d)
{
	if (d != NULL && d->cmd_path != NULL)
	{
		if (chdir(d->cmd_path) == 0)
		{
			return (0);
		}
	}
	return (1);
}
/**
 * my_his_list - Prints the the history list, one command per line
 * @d: The variable address of the data structure parameter
 *
 * Return: Always success (0)
 */

int my_his_list(data_t *d)
{
	stringnode_t *current = d->node_his;
	int file_des = STDOUT_FILENO; /*descriptor for output*/

	while (current != NULL)
	{
		write(file_des, current->s, str_len(current->s));
		write(file_des, "\n", 1);
		current = current->next;
	}
	return (0);
}
/**
 * mimic_alias - A function that is a carbon copy of the alias builtin command
 * @d: The variable address of the data structure parameter
 *
 * Return: Always Success (0)
 */

int mimic_alias(data_t *d)
{
	int result;

	result = display_alias(d->my_alias);

	return (result);
}
