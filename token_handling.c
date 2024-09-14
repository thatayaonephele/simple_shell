#include "shell.h"

/**
 * str_token - Breakdown a string int chars without repetition of delimeters
 * @s: The string input parameter to be evaluated
 * @del: The string delimeter to be used as sub-search parameter
 *
 * Return: str arr ptr adr on split success, else NULL if split failed
 */

char **str_token(char *s, char *del)
{
	int num_substrings = 1;
	char *temp = s;
	int i = 0;
	char **substrings;

	while (*temp)
	{
		if (delim_check(*temp, del))
			num_substrings++;
		temp++;
	}

	substrings = (char **)malloc((num_substrings + 1) * sizeof(char *));
	if (!substrings)
		return (NULL);

	temp = s;

	while (*temp)
	{
		if (delim_check(*temp, del))
		{
			*temp = '\0';
			substrings[i] = strdup(s);
			s = temp + 1;
			i++;
		}
		temp++;
	}
	substrings[i] = strdup(s);
	substrings[num_substrings] = NULL;

	return (substrings);
}

/**
 * str_token2 - Breaksdown a string int chars
 * @s: The string input pointer parameter to be evaluated
 * @del: The string delimeter to be used as sub-search parameter
 *
 * Return: str arr ptr adr on split success, else NULL if split failed
 */

char **str_token2(char *s, char del)
{
	int num_substrings = 1;
	char *temp = s;
	char **substrings;
	int i = 0;

	while (*temp)
	{
		if (*temp == del)
			num_substrings++;
		temp++;
	}
	substrings = (char **)malloc((num_substrings + 1) * sizeof(char *));
	if (!substrings)
		return (NULL);

	temp = s;
	while (*temp)
	{
		if (*temp == del)
		{
			*temp = '\0';
			substrings[i] = strdup(s);
			s = temp + 1;
			i++;
		}
		temp++;
	}
	substrings[i] = strdup(s);
	substrings[num_substrings] = NULL;

	return (substrings);
}
/**
 * est_input - A function that returns a line exlc. a "\n"
 * @d: The parameter struct
 *
 * Return: The amount of bytes read
 */

int getLine(data_t *d, char **my_ptr, size_t *object_size)
{

    size_t tmp;
    ssize_t result = 0, sub_str = 0;
    static char my_buffer[READ_BUF_SIZE];
    char *new_p = NULL, *chr;
    static size_t x, my_len;

    my_ptr = *my_ptr;
    if (my_ptr && object_size)
    {
        sub_str = *object_size;
    }
    if (x == my_len)
    {
        x = my_len = 0;
    }

    result = buff_read(d, my_buffer, &my_len);
    if ((result == 0 && my_len == 0) || result == -1)
    {
        return (-1);
    }

    chr = str_chr(my_buffer + x, '\n');
    if (chr != NULL)
    {
        tmp = 1 + (unsigned int)(chr - my_buffer);
    }
    else
    {
        tmp = my_len;
    }

    if (sub_str)
    {
        new_p = mem_realloc(my_ptr, sub_str, sub_str + tmp);
    }
    else
    {
        new_p = mem_realloc(my_ptr, sub_str, tmp + 1);
    }

    if (!new_p)
    {
        if (my_ptr)
        {
            free(my_ptr);
        }
        return (-1);
    }

    if (!sub_str)
    {
        str_cpy(new_p, my_buffer + x, tmp - x + 1);
    }
    else
    {
        str_ncat(new_p, my_buffer + x, tmp - x);
    }

    sub_str = sub_str + tmp - x;
    x = tmp;
    my_ptr = new_p;

    if (object_size)
    {
        *object_size = sub_str;
    }
    *my_ptr = new_p;
    return (sub_str);
}
/**
 * append_node_end - Appends a node at the end index pos of the list
 * @my_h: The ptr to the head node adrr
 * @str: The field of string type
 * @num: The node index position use for the node his
 *
 * Return: The new node repr the size of list
 */
stringnode_t *append_node_end(stringnode_t **my_h, const char *str, int num)
{
        stringnode_t *my_node, *size_of_list;

        if (!my_h)
                return (NULL);

        my_node = *my_h;
        size_of_list = malloc(sizeof(stringnode_t));
        if (!size_of_list)
                return (NULL);
        set_mem((void *)size_of_list, 0, sizeof(stringnode_t));
        (*size_of_list).num = num;
        if (str)
        {
                (*size_of_list).str = dup_str(str);
                if (!(*size_of_list).str)
                {
                        free(size_of_list);
                        return (NULL);
                }
        }

        if (!my_node)
        {
                *my_h = size_of_list;
        }
        else
                for (; (*my_node).next; my_node = (*my_node).next)
                        ;
        (*my_node).next = size_of_list;

        return (size_of_list);
}
