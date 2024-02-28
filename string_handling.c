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
/**
 * cpy_str - Returns a string copy of desired target string
 * @source: The src variable address parameter to duplicate string from
 * @destination: The dest variable address parameter to duplicate string to
 * Return: The poiter pointing to the string dest parameter
 */

char *cpy_str(char *destination, char *source)
{
	int x = 0;

	if (destination == source)
		return (destination);
	if (source == 0)
		return (destination);
	for (; source[x]; x++)
		destination[x] = source[x];
	destination[x] = 0;
	return (destination);
}
/**
 * str_len - Determines string length of input
 * @chr_str: The input string parameter to be evaluated
 *
 * Return: The input string parameter lenth
 */

int str_len(char *chr_str)
{
}

/**
 * cat_str - A function that returns 2 concatenated strings
 * @string1: the 1st destination string parameter
 * @string2: the 2nd source string parameter
 *
 * Return: The pointer pointing to the dest buffer of string 1 & 2
 */

char *cat_str(char *string1, char *string2)
{
	int len1;
	char *null_term_pos;
	int max_bytes_available;
	int bytes_to_concatenate;

	len1 = 0;
	while (string1[len1] != '\0')
		len1++;

	/*find position of null terminator in string2*/
	null_term_pos = _str_chr(string2, '\0');

	max_bytes_available = BUFFER_SIZE - len1;

	bytes_to_concatenate = null_term_pos - string2;
	if (bytes_to_concatenate > max_bytes_available)
		bytes_to_concatenate = max_bytes_available;

	_str_ncat(string1, string2, bytes_to_concatenate);

	return (string1);
}
