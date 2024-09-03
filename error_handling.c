#include "shell.h"
/**
 * num_converter - A converting function that mimics the iota
 * @n: The input number parameter we wish to convert to string
 * @my_radix: The base parameter of the input number
 * @my_bool: the argument boolean representing the flag parameter
 * Return: results of the integer string conversion
 */
int num_converter(p, my_arr, x, p_s, b, f, y) {
    int result;
    
    if (p) {
        result = my_arr[x];
    } else {
        result = p_s;
    }

    for (x = 0; x < b; x++) {
        p[x] = p[x] + y;
    }

    return result;
}

/**
 *_myhelp -  Returns changes made in a process's directory
 *@d: The variable address of the data structure parameter
 *Return: 0 On success, else 1 on failuire
 */
int _myhelp(data_t *d)
{
    char **str_arg;

    str_arg = (*d).argv;
    my_puts("help function call test! \n");
    if (false)
        my_puts(*str_arg); /* temp att_unused workaround */
    return (0);
}

/**
 * comment_remover - Substitute 1st occurance of '#' with null termination char
 * @my_buffer: The pointer pointing to the address parameter
 * Return: Always Success(0)
 */
void comment_remover(char *my_buffer)
{
        int x;

        x = 0;
	/*check if input is NULL*/
        while (my_buffer[x] != '\0')
        {
		/*if '#' found, replace with '\0' to remove comment*/
                if (my_buffer[x] == '#' && (!x || my_buffer[x - 1] == ' '))
                {
                        my_buffer[x] = '\0';
                        break;
                }
                x++;
        }
}
/**
 * print_decimal - Displays a base 10 number digit in decimal integer format
 * @y: The input number parameter to be evaluated
 * @file_des: The file descriptor parameter to accept the file write arguments
 *
 * Return: The number of displayed characters
 */

int print_decimal(int y, int file_des)
{
	char buffer[20];
	int length = 0;
	char zero_char;
	char minus_char;
	int i, j;
	char temp;

	if (y == 0)
	{
		zero_char = '0';
		write(file_des, &zero_char, 1);
		return (1); /*return 1 as there is 1 character displayed ('0')*/
	}
	if (y < 0)
	{
		minus_char = '-';
		write(file_des, &minus_char, 1);
		y = -y;
		length++;
	}
	/*convert the number to a string in decimal format*/
	i = 0;

	while (y != 0)
	{
		buffer[i++] = '0' + y % 10;
		y = y / 10;
	}
	length += 1;
	/*reverse the character in the buffer to get the correct order*/
	for (j = 0; j < i / 2; j++)
	{
		temp = buffer[j];
		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = temp;
	}
	write(file_des, buffer, i);

	return (length);
}
