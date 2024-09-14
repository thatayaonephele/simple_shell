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
/**
 * atoi_err - converts a string to an integer
 * @sub_str: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int atoi_err(char *sub_str)
{
	unsigned long int output = 0;
        int x = 0;

        if (*sub_str == '+')
                sub_str++;

        x = 0;
        while (sub_str[x] != '\0')
        {
                if (*(sub_str + x) <= '9' && *(sub_str + x) >= '0')
                {
                        output = output * 10;
                        output = output + (sub_str[x] - '0');
                        if (output > INT_MAX)
                                return (-1);
                }
                else
                        return (-1);

                x = x + 1;
        }
        return (output);
}
