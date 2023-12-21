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
