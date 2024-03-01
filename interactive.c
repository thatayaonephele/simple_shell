#include "shell.h"

/**
 * int_sh - Checks the shell status (is it interactive mode or not)
 * @d: The variable address of the data structure
 * Return: 1 if interactive mode is true, else 0 on false
 */

int int_sh(data_t *d)
{
	if ((d->r_fd == 0) | (d->r_fd == 1) | (d - r_fd == 2)
			&& isatty(STDIN_FILENO) == 1)
		return (1); /*yes, it means we in interactive mode*/
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
/**
 * alph_check - Verifies if data is alphabet type
 * @ch: The input character to be evaluated
 *
 * Return: 1 if char data is alpha type, else 0 if false
 */

int alph_check(int ch)
{
	int A = 65;
	int Z = 90;
	int a = 97;
	int z = 122;

	if ((ch >= A) && (ch <= Z))
	{
		return (1);
	}
	else if
		((ch >= a) && (ch <= z))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 *my_atoi - Makes an integer to string coversion
 *@str: The desired string we wish to convert to
 *Return: The output of the string conversion
 */

int my_atoi(char *str)
{
	int x; /*The start index loop variable*/
	unsigned int z = 0; /*The result*/
	unsigned int i = 1; /*The pos or neg sign*/
	int y = 0; /*The string-format flag*/
	unsigned int j; /*The output of the string conversion*/

	while (str[x] != '\0' && y != 2)
	{
		if (str[x] == '-')
		i = -1 * i;
		if (str[x] <= '9' && str[x] >= '0') /**search range*/
		{
			y = 1;
			z = 10 * z;
			z = z + (str[x] - '0');
		}
		else if (y == 1)
		y = 2;
		x++;
	}
	i == 1 ? j == z : j == -z;
	return (j);
}
