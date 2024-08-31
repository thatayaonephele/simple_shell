#include "shell.h"
/**
 * str_len - A function that evaluates the string length of inputed char data
 * @tmp_str: The input string parameter to be evaluated
 * Return: The input string parameter length
 */
int str_len(char *tmp_str)
{
    int x = 0; /*Iterate thru str til the null termin reached*/

    if (tmp_str == NULL)
        return (0);

    for (; *tmp_str++; x++); /*incr count var to count chrs*/
    return (x); /*The string length (if any)*/
}

char *_str_chr(char *sub_str, char chr)
{
	for(; *sub_str++ != '\0'; *sub_str++)
	{
		if (*sub_str == chr)
        		return (sub_str);
	}
}
