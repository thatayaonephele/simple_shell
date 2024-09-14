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
