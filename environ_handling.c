#include "shell.h"

/**
 * unset_my_env - Remove an enviroment variable
 * @d: The variable address of the data structure parameter
 *
 * Return: 0 on success removal, 1 on failure
 */

int unset_my_env(data_t *d)
{
	int i, j;
	char **new_env;

	if (d->arg == NULL)
		return (1);

	for (i = 0; d->environ[i] != NULL; i++)
		;
	new_env = malloc(sizeof(char *) * i);

	if (new_env == NULL)
		return (1);

	for (i = 0, j = 0; d->environ[i] != NULL; i++)
	{
		if (lexi_cmp(d->environ[i], d->arg) != 0)
		{
			new_env[j] = d->environ[i];
			j++;
		}
	}
	new_env[j] = NULL;

	free(d->environ);

	d->environ = new_env;

	return (0);
}
/**
 * append_env_list - Appends vars to a linked list of env
 * @d: The variable address of the data structure parameter
 * Return: Always Success (0)
 */
int append_env_list(data_t *d)
{
    size_t x;
    stringnode_t *my_node = NULL;

    x = 0;

    while (environ[x])
    {
        add_node_end(&my_node, environ[x], 0);
        x++;
    }

    (*d)._env = my_node;
    return (0);
}
/**
 * set_my_env - Initialize or modify a variable environment
 * @d: The variable address of the data structure parameter
 *
 * Return: 0 on success, else 1 on error
 */

int set_my_env(data_t *d)
{
	int i;

	if (d == NULL || d->str_env_var == NULL || d->str_var == NULL)
		return (1);

	if (unset_my_env(d) != 0)
		return (1);

	i = 0;

	while (d->environ[i] != NULL)
	{
		if (lexi_cmp(d->environ[i], d->str_env_var) == 0)
		{
			free(d->environ[i]);
			d->environ[i] = _str_ncpy(NULL, d->str_env_var, str_len(d->str_env_var));
			d->environ[i] = _str_ncpy(d->environ[i], "=", 1);
			d->environ[i] = _str_ncpy(d->environ[i], d->str_var, str_len(d->str_var));
			return (0);
		}
		i++;
	}
	d->environ[i] = _str_ncpy(NULL, d->str_env_var, str_len(d->str_env_var));
	d->environ[i] = _str_ncpy(d->environ[i], "=", 1);
	d->environ[i] = _str_ncpy(d->environ[i], d->str_var, str_len(d->str_var));
	d->environ[i + 1] = NULL;

	if (append_env_list(d) != 0)
	{
		perror("append_env_list");
		return (1);
	}
	return (0);
}
/**
 * current_env - Displays the environment of the current directory
 * @d: parameter struct
 * Return: Always (0)
 */
int current_env(data_t *d)
{
        display_str_element((*d)._env);
        return (0);
}
/**
 * est_env_val - gets the value of an environment variable
 * @d: The parameter struct
 * @my_str: Name of the environment variable
 *
 * Return: the value
 */
char *est_env_val(data_t *d, const char *my_str)
{
    char *ptr;
    stringnode_t *my_node = (*d)._env;

    while (my_node != NULL)
    {
        ptr = hay_start((*my_node).str, my_str);
        if (ptr && *ptr)
            return (ptr);
        my_node = (*my_node).next;
    }
    return (NULL);
}
