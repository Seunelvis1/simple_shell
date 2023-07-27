#include "shell.h"

/**
 **_strncpy - it copies a string
 *@dest: the destination string
 *@src: the source string
 *@num: number of characters to copy
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int num)
{
	int a, b;
	char *s = dest;

	a = 0;
	while (src[a] != '\0' && a < num - 1)
	{
		dest[a] = src[a];
		a++;
	}
	if (a < num)
	{
		b = a;
		while (b < num)
		{
			dest[b] = '\0';
			b++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: first str
 *@src: second str
 *@num: max no of byte to use
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int num)
{
	int a, b;
	char *s = dest;

	a = 0;
	b = 0;
	while (dest[a] != '\0')
		a++;
	while (src[b] != '\0' && b < num)
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	if (b < num)
		dest[a] = '\0';
	return (s);
}

/**
 **_strchr - it locates a character in a string
 *@str: string to be parsed
 *@ch: character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *str, char ch)
{
	do {
		if (*str == ch)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
