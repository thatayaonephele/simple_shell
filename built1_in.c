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
 * mimic_alias - A function that is a carbon copy of the alias builtin command
 * @d: The variable address of the data structure parameter
 *
 * Return: Always Success (0)
 */
int mimic_alias(data_t *d)
{
    int x = 0;
    char *ptr = NULL;
    stringnode_t *my_node = NULL;

    if ((*d).argc == 1)
    {
        my_node = (*d).my_alias;
        for (; my_node; my_node = (*my_node).next)
        {
            display_alias(my_node);
        }
        return (0);
    }
    for (x = 1; (*d).argv[x]; x++)
    {
        ptr = str_chr((*d).argv[x], '=');
        if (ptr == NULL)
            display_alias(n_s_w((*d).my_alias, (*d).argv[x], '='));
        else
            add_alias(d, (*d).argv[x]);
    }
    return (0);
}
/**
 * my_his - A function that lists history, shows 1 cmd/line, followed
 *              by line no.s,commencing at 0.
 * @d: The variable address of the data structure parameter
 * Return: Always (0)
 */
int my_his(data_t *d)
{
        display_list((*d).node_his);
        return (0);
}
