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
/**
 * add_env - Establish a new enviroment variable if it doesnt exist
 * @d: The variable address of the data structure parameter
 * @str_env_var: The variable parameter of the string enviroment
 * @str_var: The variable value of the string enviroment
 *
 * Return: Always Success (0)
 */

int add_env(data_t *d, char *str_env_var, char *str_var)
{
	int i;
	char **new_environ;
	size_t env_size = 0;

	if (!d || !str_env_var || !str_var)
		return (1);

	for (i = 0; d->environ[i] != NULL; i++)
		env_size++;

	new_environ = malloc((env_size + 2) * sizeof(char *));

	if (!new_environ)
		return (1);

	for (i = 0; d->environ[i] != NULL; i++)
		new_environ[i] = d->environ[i];

	new_environ[env_size] = _str_ncpy(NULL, str_env_var, str_len(str_env_var));
	new_environ[env_size] = _str_ncat(new_environ[env_size], "=", 1);
	new_environ[env_size] = _str_ncat(new_environ[env_size],
			str_var, str_len(str_var));

	new_environ[env_size + 1] = NULL;

	free(d->environ);
	d->environ = new_environ;

	return (0);
}
