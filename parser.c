#include "shell.h"

/**
 * is_cmd - will make to wether a file is executable command
 * @info: struct info
 * @path: file path
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - characters duplicator
 * @pathstr: PATH string
 * @start: beginning index
 * @stop: ending index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int j = 0, l = 0;

	for (l = 0, j = start; j < stop; j++)
		if (pathstr[j] != ':')
			buf[l++] = pathstr[j];
	buf[l] = 0;
	return (buf);
}

/**
 * find_path - gets this cmd in the PATH string
 * @info: struct info
 * @pathstr: string PATH
 * @cmd: cmd to find
 *
 * Return: full path of cmd if found else NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int j = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[j] || pathstr[j] == ':')
		{
			path = dup_chars(pathstr, curr_pos, j);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[j])
				break;
			curr_pos = j;
		}
		j++;
	}
	return (NULL);
}
