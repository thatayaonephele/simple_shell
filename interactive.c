#include "shell.h"
/**
 * int_sh - Checks the shell status (is it interactive mode or not)
 * @d: The variable address of the data structure
 * Return: 1 if interactive mode is true, else 0 on false
 */
int int_sh(data_t *d)
{
        return (isatty(STDIN_FILENO) && (*d).readfd <= 2);
}
/**
 * delim_check - Verfies if delimeter(s) are present in a set of characters
 * @ch: The character input to be verified
 * @delimeter: The string delimeter parameter
 * Return: 1 if delimeters are present, else 0
 */
int delim_check(char ch, char *delimeter)
{
        for (; *delimeter; delimeter++)
        {
                if (*delimeter == ch)
                        return (1);
        }
        return (0);
}
/**
 * alph_check - Verifies if data is alphabet type
 * @ch: The input character to be evaluated
 * Return: 1 if char data is alpha type, else 0 if false
 */
int alph_check(int ch)
{
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        return 1;
    else
        return 0;
}
/**
 *my_atoi - Makes an integer to string coversion
 *@str: The desired string we wish to convert to
 *Return: The output of the string conversion
 */
int my_atoi(char *str)
{
    unsigned int output = 0;
    int x = 0, p_n = 1, buff_f = 0, o_p;

    while (str[x] != '\0' && buff_f != 2)
    {
        if (str[x] == '-')
            p_n = p_n * (-1);

        if (str[x] >= '0' && str[x] <= '9')
        {
            buff_f = 1;
            output = output * 10;
            output = output + (str[x] - '0');
        }
        else if (buff_f == 1)
            buff_f = 2;

        x++;
    }

    if (p_n == -1)
        o_p = -output;
    else
        o_p = output;

    return (o_p);
}
