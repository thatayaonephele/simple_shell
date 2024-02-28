#include "shell.h"

/**
 * reverse_string - reverses string
 * @str: string to reverse
 *
 * Return: string
 */

char *reverse_string(char *str)
{
	int start, end;
	char temp;

	start = 0;
	end = strlen(str) - 1;

	while (start < end)
	{
		temp = str[start];
		str[start++] = str[end];
		str[end--] = temp;
	}
	return (str);
}

/**
 * num_converter - A converting function that mimics the iota
 * @n: The input number parameter we wish to convert to string
 * @my_radix: The base parameter of the input number
 * @my_bool: the argument boolean representing the flag parameter
 *
 * Return: results of the integer string conversion
 */

char *num_converter(long int n, int my_radix, int my_bool)
{
	int max_digits = 64; /*maximum num of digits in results*/
	char *result = malloc(sizeof(char) *  max_digits);
	int i = 0;
	int is_negative = 0;

	if (n == 0) /*spcial case: number is zero*/
	{
		result[i++] = '0';
	}
	else
	{
		if (n < 0 && my_bool)/*check if conversion number is negative*/
		{
			is_negative = 1;
			n = -n;/*make num posiitive for conversions*/
		}
		/*perform conversion from number to string representation*/
		while (n != 0 && i < max_digits)
		{
			int digit = n % my_radix;

			result[i++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
			n /= my_radix;
		}
		if (is_negative && i < max_digits) /*add negative sign if necessary*/
		{
			result[i++] = '-';
		}
	}

	result[i] = '\0';

	return (reverse_string(result));
}
/**
 *_myhelp -  Returns changes made in a process's directory
 *@d: The variable address of the data structure parameter
 *Return: 0 On success, else 1 on failuire
 */

int _myhelp(data_t *d)
{
	char **str_arg;

	str_arg = d->argv; /**set the argument string to arg vector in struct*/
	my_puts("Help  not fully functional, call Motalepule Lmao ka dlala \n");
	if (!(1))
		my_puts(*str_arg);
	return (0);
}
