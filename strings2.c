#include "shell.h"
/**
 * str_len - A function that evaluates the string length of inputed char data
 * @chr_str: The input string parameter to be evaluated
 * Return: The input string parameter length
 */
int str_len(char *chr_str)
{
	int length; /*Iterate thru str until the null terminator is reached*/

	for (length = 0; *chr_str != 0; length++)
		chr_str++; /*increment counter var to count chrs*/
	return (length); /*The string length (if any)*/
}
