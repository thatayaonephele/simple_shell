#include "shell.h"

/**
 * str_token - Breakdown a string int chars without repetition of delimeters
 * @s: The string input parameter to be evaluated
 * @del: The string delimeter to be used as sub-search parameter
 *
 * Return: str arr ptr adr on split success, else NULL if split failed
 */

char **str_token(char *s, char *del)
{
	int num_substrings = 1;
	char *temp = s;
	int i = 0;
	char **substrings;

	while (*temp)
	{
		if (delim_check(*temp, del))
			num_substrings++;
		temp++;
	}

	substrings = (char **)malloc((num_substrings + 1) * sizeof(char *));
	if (!substrings)
		return (NULL);

	temp = s;

	while (*temp)
	{
		if (delim_check(*temp, del))
		{
			*temp = '\0';
			substrings[i] = strdup(s);
			s = temp + 1;
			i++;
		}
		temp++;
	}
	substrings[i] = strdup(s);
	substrings[num_substrings] = NULL;

	return (substrings);
}

/**
 * str_token2 - Breaksdown a string int chars
 * @s: The string input pointer parameter to be evaluated
 * @del: The string delimeter to be used as sub-search parameter
 *
 * Return: str arr ptr adr on split success, else NULL if split failed
 */

char **str_token2(char *s, char del)
{
	int num_substrings = 1;
	char *temp = s;
	char **substrings;
	int i = 0;

	while (*temp)
	{
		if (*temp == del)
			num_substrings++;
		temp++;
	}
	substrings = (char **)malloc((num_substrings + 1) * sizeof(char *));
	if (!substrings)
		return (NULL);

	temp = s;
	while (*temp)
	{
		if (*temp == del)
		{
			*temp = '\0';
			substrings[i] = strdup(s);
			s = temp + 1;
			i++;
		}
		temp++;
	}
	substrings[i] = strdup(s);
	substrings[num_substrings] = NULL;

	return (substrings);
}
