#include "shell.h"
/**
 *alph_check - Verifies if an int data is an alphabet type
 *@chr: The input character to be evaluated
 *Return: 1 if char data is alpha type, else 0 if false
 */
int alph_check(int chr)
{
	return ((chr >= 'a' && chr <= 'z') || (chr >= 'A' && chr <= 'Z'));
}
/**
 * _str_cat - A function that concatenates two strings.
 * @dest : The input destination value
 * @src: The source input value
 * Return: Always Success (0)
 */
char *_str_cat(char *dest, char *src)
{
	int x = 0, y = 0;

	while (dest[x] != '\0') /*iterate as long as null term not reached*/
		x++;
	while (src[y] != '\0') /*iterate as long as null term chr not reached*/
	{
		dest[x] = src[y]; /*swap the string values*/
		x++, y++; /*move to next loop index*/
	}
	dest[x] = '\0'; /*set last dest val at index x to null term chr*/
	return (dest); /*print the desired concatenated str*/
}
/**
 *_str_ncat - A function that concatenates 2 given strings
 *@end_pos: Sub string 1
 *@start_pos: Sub string 2
 *@num: The byte size to be fed into the buffer
 *Return: The result of the 2 strings concatenated
 */
char *_str_ncat(char *end_pos, char *start_pos, int num)
{
    char *z = end_pos;
    int y = 0, x = 0;

    while (end_pos[x] != '\0')
        x++;
    
    while (start_pos[y] != '\0' && y < num)
    {
        end_pos[x] = start_pos[y];
        x++;
        y++;
    }

    if (y < num)
        end_pos[x] = '\0';
    
    return (z);
}
