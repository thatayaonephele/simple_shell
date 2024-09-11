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
 * @str: The inputed string var we wish to see on stdout
 * Return: Void Function (No Return)
 */

void my_puts(char *str)
{
	int x = 0;

	if (str == NULL)
		return;
	for (; str[x] != '\0'; x++)
		_putchar(str[x]);
}
/**
 *fd_puts - Write out file descriptor to target destination the inputed string
 * @str: The inputed string parameter to be displayed
 * @file_des: The file descriptor parameter
 * Return: The amount of characters parsed to the function
 */
int fd_puts(char *str, int file_des)
{
    int x = 0;

    if (str == NULL)
        return (0);

    for (; *str; str++)
    {
        x += fd_put(*str, file_des);
    }
    return (x);
}
/**
 * fd_put - writes the character ch to the given file_des
 * @ch: The character to print
 * @file_des: The file descriptor being written to
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int fd_put(char ch, int file_des)
{
    static int x;
    static char my_buf[WRITE_BUF_SIZE];

    if (ch == BUF_FLUSH || x >= WRITE_BUF_SIZE)
    {
        write(file_des, my_buf, x);
        x = 0;
    }
    if (ch != BUF_FLUSH)
    {
        buf[x++] = ch;
    }
    return (1);
}
/**
 * disp_err - A function that displays messages of error type
 * @d: The struct parameter
 * @str_err_type: The str parameter having specified err type
 * Return: -1 on err, 0 if no no.s in str, else converted num
 */
void disp_err(data_t *d, char *str_err_type)
{
    error_puts((*d).file_name);
    error_puts(": ");
    disp_d((*d).count_line, STDERR_FILENO);
    error_puts(": ");
    error_puts((*d).argv[0]);
    error_puts(": ");
    error_puts(str_err_type);
}
