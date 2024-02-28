#include "shell.h"

/**
 *find_env - A function that makes a duplicate of eviron in string array format
 *@d: The variable address of the data structure parameter
 *Return: The string array copy of environ
 */
char **find_env(data_t *d)
{
	if (!d->environ || d->changed_env)
	{
		d->environ = list_to_str(d->_env);
		d->changed_env = 0;
	}
	return (d->environ);
}

/**
 * del_env - A function that deletes a variable of an enviroment
 * @d: The variable address of the data structure parameter
 * @str_env_var: The variable parameter of the string enviroment
 *
 * Return: 1 successful deletion, else 0 on failure
 */

int del_env(data_t *d, char *str_env_var)
{
	linked_str *current = d->_env;
	linked_str *prev = NULL;

	/*search for the enviroment variable*/
	while (current != NULL)
	{
		if (strcmp(current->s, str_env_var) == 0)
		{
			/*remove the env variable from linked list*/
			if (prev == NULL)
			{
				d->_env = current->next;
			}
			else
			{
				prev->next = current->next;
			}
			free(current->s);
			free(current);

			return (1);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}
