#include "shell.h"

/**
 * _strcpy - it copies a string
 * @dest: the destination
 * @src: the source string
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int j = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}

/**
<<<<<<< HEAD
 * _strdup - copies  a string
 * @str: the string to copy *
 * Return: pointer to the copies string
=======
 * _strdup - it duplicates a string
 * @str: the string to be duplicated
 *
 * Return: a pointer to the duplicated string
>>>>>>> 649a8c2e5377ed57de4bb5fe25d2d47d59b9699e
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _puts - it prints an inputed string
 * @str: the string to print
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_putchar(str[j]);
		j++;
	}
}

/**
<<<<<<< HEAD
 * _putchar - writes the char c to stdout
 * @c: The char to print
=======
 * _putchar - writes character to standard output
 * @c: The character to output
>>>>>>> 649a8c2e5377ed57de4bb5fe25d2d47d59b9699e
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(1, buf, j);
		j = 0;
	}
	if (c != BUF_FLUSH)
		buf[j++] = c;
	return (1);
}
