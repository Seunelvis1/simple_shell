#include "shell.h"

/**
 * interactive - check if shell is in interactive mode
 * @inf: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_delim - to check for a delimeter
 * @d: the char to check
 * @delim: delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char d, char *delim)
{
	while (*delim)
		if (*delim++ == d)
			return (1);
	return (0);
}

/**
 * _isalpha - to check for alphabetic character
 * @d: character to check
 * Return: 1 if alphabetic, 0 if otherwise
 */

int _isalpha(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - to convert a string to an integer
 * @a: string to convert
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *a)
{
	int j, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (j = 0; a[j] != '\0' && flag != 2; j++)
	{
		if (a[j] == '-')
			sign *= -1;

		if (a[j] >= '0' && a[j] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (a[j] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

