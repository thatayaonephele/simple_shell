#include "shell.h"

/**
 * _change_dir - Returns the changes made in the current user directory
 * @d: Structure containing potential arguments. Used to maintain
 *
 * Return: Always Success(0)
 */
int _change_dir(data_t *d)
{
	if (d == NULL || d->path == NULL)
	{
		write(STDERR_FILENO, "Invalid data_t or path argument.\n",
				strlen("Invalid data_t or path argument.\n"));
		return (-1);
	}
	if (chdir(d->path) == -1)
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
	if (d != NULL && d->path != NULL)
	{
		if (chdir(d->path) == 0)
		{
			return (0);
		}
	}
	return (1);
}
