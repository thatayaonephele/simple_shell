#include "shell.h"
/**
 * lexi_cmp - 2 strings lexicogarphic comparison
 * @first_str: The 1st string variable part of the comparision
 * @second_str: The 2nd string variable part of the comparision
 * Return: For s1 < s2, return -1, s1 == s2 return 0, s1>s2 return 1
 */

int lexi_cmp(char *first_str, char *second_str)
{
	for (; *first_str && *second_str; first_str++, second_str++)
	{
		if (*first_str != *second_str)
			return (*first_str - *second_str);
	}
	if (*second_str > *first_str)
		return (1);
	else if (*second_str < *first_str)
		return (-1);
	else
		return (0);
}
