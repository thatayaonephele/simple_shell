#include "shell.h"

/**
 * _putchar - A function that prints to the std out the character c
 * @chr: The char variable parameter to be written to out
 * Return: 1 on success of writing c char to stdout, else 0 on failuire
 */

int _putchar(char chr)
{
	static int x;
	static char my_buffer[BUFFER_SIZE];

	if (x >= BUFFER_SIZE)
	{
		write(1, my_buffer, x);
		x = 0;
	}
	if (chr == BUF_FLUSH)
	{
		write(1, my_buffer, x);
		x = 0;
	}
	if (chr != BUF_FLUSH)
		my_buffer[x++] = chr;
	return (1);
}

/**
 * my_puts - A function that takes an input string & returns it on std out
 * @s: The inputed string var we wish to see on stdout
 * Return: Void Function (No Return)
 */

void my_puts(char *s)
{
	int x = 0;

	if (s == NULL)
		return;
	for (; s[x] != '\0'; x++)
		_putchar(s[x]);
}
/**
 *fd_puts - Write out file descriptor to target destination the inputed string
 * @s: The inputed string parameter to be displayed
 * @file_des: The file descriptor parameter
 * Return: The amount of characters parsed to the function
 */

int fd_puts(char *s, int file_des)
{
	int x = 0;

	if (s == NULL)
		return (0);
	while (!(*s) == false)
	{
		x = x + fd_put(*s++, file_des);
	}
	return (x);
}
