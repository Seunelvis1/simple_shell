#include "shell.h"

/**
 * _eputs - it prints an input string
 * @s: string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *s)
{
	int j = 0;

	if (!s)
		return;
	while (s[j] != '\0')
	{
		_eputchar(s[j]);
		j++;
	}
}

/**
 * _eputchar - it writes a character to stderr
 * @ch: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char ch)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (ch != BUF_FLUSH)
		buf[j++] = ch;
	return (1);
}

/**
 * _putfd - it writes the character ch to given fd
 * @ch: character to print
 * @fd: filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char ch, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buf[i++] = ch;
	return (1);
}

/**
 * _putsfd - it prints an input string
 * @str: string to be printed
 * @fd: filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		j += _putfd(*str++, fd);
	}
	return (j);
}
