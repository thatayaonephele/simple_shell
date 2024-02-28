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
		if (strcmp(d->environ[i], d->arg) != 0)
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
