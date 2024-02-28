#include "shell.h"

/**
 * curr_char_buff - Verifies chain delimeter existance of char in current buff
 * @data: The address variable of the structure parameter
 * @ptr: Current index in buffer parameter address
 * @ch_buff: The character parameter buffer
 * Return: 1 if chain delimeter exists, else 0 if it DNE
 */

int curr_char_buff(data_t *data, char *ch_buff, size_t *ptr)
{
	char current_char;

	current_char = data->arg[*ptr];

	while (current_char != '\0')
	{
		if (current_char == *ch_buff)
		{
			return (1);
		}
		(*ptr)++;
		current_char = data->arg[*ptr];
	}
	return (0);
}
