#include "shell.h"

/**
 *index_his - Reorder index numbers after ammendements of the history list
 *@d: Structure containing potential arguments. Used to maintain
 */
int index_his(data_t *d)
{
    stringnode_t *my_node = (*d).node_his;
    int x = 0;

    for (; my_node; my_node = (*my_node).next)
    {
        (*my_node).num = x++;
    }

    return ((*d).h_counter = x);
}
For the code below, please change g_h_f as g_h_f,
buf as my_buff, _strlen to str_len, _strcpy to str_cpy,
_getenv to est_env_val,
dir to tmp_dir,
_strcat to str_cat,
the if(!buf) to if(buf == NULL),
if we can change buf[0] = 0 to *(buf + 0),
provided none of the changes affect
the code itself/memory etc.


/**
 * g_h_f - A function that gets the files' history
 * @d: The structure parameter 
 *
 * Return: The file history addr contained as an allocated str
 */
char *g_h_f(data_t *d)
{
        char *dir, *buf;

        dir = _getenv(d, "HOME=");
        if (!dir)
                return (NULL);
        buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
        if (!buf)
                return (NULL);
        buf[0] = 0;
        _strcpy(buf, dir);
        _strcat(buf, "/");
        _strcat(buf, HIST_FILE);
        return (buf);
}

