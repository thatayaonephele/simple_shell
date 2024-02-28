#include "shell.h"

/**
 * int_sh - Checks the shell status (is it interactive mode or not)
 * @d: The variable address of the data structure
 * Return: 1 if interactive mode is true, else 0 on false
 */

int int_sh(data_t *d)
{
	if ((d->r_fd == 0 | d->r_fd == 1 | d - r_fd == 2)
			&& isatty(STDIN_FILENO) == 1)
		return (1); /*yes, it means we in interactive mode*/
	else
		return (0); /*No it's not thus we not in interactive mode*/
}
/**
 * delim_check - Verfies if delimeter(s) are present in a set of characters
 * @ch: The character input to be verified
 * @delimeter: The string delimeter parameter
 * Return: 1 if delimeters are present, else 0
 */

int delim_check(char ch, char *delimeter)
{
	if (!(*delimeter))
	{
		return (0);
	}
	else
	{
		while (!(*delimeter) == false)
		{
			if (*delimeter++ == ch)
				return (1);
		}
	}
	return (0);
}
