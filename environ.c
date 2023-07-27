#include "shell.h"

/**
 * _myenv - to print the current environment
 * @info: contains arguments
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - it gets the value of an environ variable
 * @info: Structure contains arguments
 * @n: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *info, const char *n)
{
	list_t *node = info->env;
	char *q;

	while (node)
	{
		q = starts_with(node->str, n);
		if (q && *q)
			return (q);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize or creates an environmane var
 * @info: Structure containing potential arguments
 *  Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - to remove an environment variable
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int j;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (j = 1; j <= info->argc; j++)
		_unsetenv(info, info->argv[j]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure contains arguments
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		add_node_end(&node, environ[j], 0);
	info->env = node;
	return (0);
}
