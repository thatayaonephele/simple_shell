#include "shell.h"
/**
 * mem_realloc - a function that reallocates a memory block
 * @ptr: A pointer pointing to the old memory block
 * @old_size: Old memory block byte size
 * @new_size: New memory block byte size
 * Return: A pointer to the reallocated memory block,
 * or NULL if the reallocation fails
 */
void *mem_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (ptr != NULL && new_size == 0)
	{
		free(ptr); /*Deallocte the memory*/
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (!ptr) /*Test for malloc failuire*/
			return;
	}
	if (new_size == old_size) /*Test if mem blocks are the same*/
	{
		return (ptr);
	}
	free(ptr); /*Deallocate the memory*/
	ptr = malloc(new_size);
	if (!(ptr)) /*Test for mem alloc success*/
		return;
	return (ptr);
}
/**
 * free_vars - Nullify variable address and free the pointer variable
 * @p: The pointer address pointing to a pointer variable to be freed
 *
 * Return: 1 if vars were successfully freed, else 0 on failure
 */

int free_vars(void **p)
{
	if (p != NULL && *p != NULL)
	{
		free(*p);
		*p = NULL;
		return (1);
	}
	return (0);
}
/**
 * set_mem - fills a block of memory with a given byte value
 * @str: The pointer to the memory block to be filled
 * @my_byte: The byte value to fill the memory block with
 * @fill_amount: The number of bytes to fill
 *
 * Return: Pointer to the filled memory block ptr_str area
 */
char *set_mem(char *ptr_str, char my_byte, unsigned int fill_amount)
{
        unsigned int x = 0;

        while (x < fill_amount)
        {
                *(ptr_str + x) = my_byte;
                x++;
        }

        return (ptr_str);
}
/**
 * r_his - A function that intakes a files' history
 * @d: the parameter struct
 *
 * Return: h_count
 */
int r_his(data_t *d)
{
    
    char *my_buff = NULL, *n_o_f = get_history_file(d);
    int x, dest = 0, my_count = 0;
    struct stat st;
    ssize_t file_des, len_reader, file_s = 0;

    if (n_o_f == NULL)
        return (0);

    file_des = open(n_o_f, O_RDONLY);
    free(n_o_f);
    if (file_des == -1)
        return (0);
    if (!fstat(file_des, &st))
        file_s = st.st_size;
    if (file_s < 2)
        return (0);
    my_buff = malloc(sizeof(char) * (file_s + 1));
    if (my_buff == NULL)
        return (0);
    len_reader = read(file_des, my_buff, file_s);
    my_buff[file_s] = 0;
    if (len_reader <= 0)
        return (free(my_buff), 0);
    close(file_des);

    x = 0;
    while (x < file_s)
    {
        if (my_buff[x] == '\n')
        {
            my_buff[x] = 0;
            b_h_l(d, my_buff + dest, my_count++);
            dest = x + 1;
        }
        x++;
    }

    if (dest != x)
        b_h_l(d, my_buff + dest, my_count++);
    free(my_buff);
    (*d).h_counter = my_count;

    for (; (*d).h_counter-- >= HIST_MAX;)
        d_n_a_i(&(*d).node_his, 0);

    index_his(d);
    return ((*d).h_counter);
}
/**
 * b_h_l - A function that adds to a linked list an entry to a history
 * @d: The struct parameter.
 * @my_buff: The buffer parameter.
 * @count_line: the histcount, history & the linecount.
 * Return: Always (0).
 */
int b_h_l(data_t *d, char *my_buff, int count_line)
{
        stringnode_t *my_node = NULL;

        if ((*d).node_his)
                my_node = (*d).node_his;

        append_node_end(&my_node, my_buff, count_line);

        if (!(*d).node_his)
                (*d).node_his = my_node;
        return (0);
}
