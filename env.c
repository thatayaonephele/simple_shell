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
	stringnode_t *current = d->_env;
	stringnode_t *prev = NULL;

	/*search for the enviroment variable*/
	while (current != NULL)
	{
		if (lexi_cmp(current->s, str_env_var) == 0)
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


/**
 * add_env - Establish a new environment variable if it doesn't exist
 * @d: The variable address of the data structure parameter
 * @str_env_var: The variable parameter of the string environment
 * @str_var: The variable value of the string environment
 *
 * Return: Always Success (0)
 */
int add_env(data_t *d, char *str_env_var, char *str_var)
{
    char *ptr;
    stringnode_t *my_node;
    char *my_buff = NULL;

    if (str_env_var == NULL || str_var == NULL)
        return (0);

    my_buff = malloc(str_len(str_env_var) + str_len(str_var) + 2);
    if (my_buff == NULL)
        return (1);

    _str_cpy(my_buff, str_env_var);
    _str_cat(my_buff, "=");
    _str_cat(my_buff, str_var);

    for (my_node = (*d).env; my_node; my_node = (*my_node).next)
    {
        ptr = hay_start((*my_node).str, str_env_var);
        if (ptr && *ptr == '=')
        {
            free((*my_node).str);
            (*my_node).str = my_buff;
            (*d).env_changed = 1;
            return (0);
        }
    }

    append_node_end(&((*d).env), my_buff, 0);
    free(my_buff);
    (*d).env_changed = 1;
    return (0);
}
