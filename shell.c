#include "shell.h"

/**
 * main - Simple unix shell
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char *av[])
{
	char *cmd = NULL;
	int status = 0;
	size_t n = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();
		if (getline(&cmd, &n, stdin) == -1)
		{
			if (cmd)
				free(cmd);
			if (isatty(STDIN_FILENO))
				_putchar('\n');
			exit(EXIT_SUCCESS);
		}
		remove_space(cmd);
		if (_strlen(cmd) == 0)
			continue;

		if (builtin(cmd) == 1)
			continue;

		else if (builtin(cmd) == 0)
			free(cmd), exit(EXIT_SUCCESS);
		if (ac > 0 && _strncmp(cmd, "/bin/", 5) == 0)
		{
			status = path_ls_bin(cmd, av);
			if (status == 1)
				continue;
		}
		else if (ac > 0 && _strncmp(cmd, "/bin/", 5) != 0)
		{
			status = path_ls(cmd, ac, av);
			if (status == 1)
				continue;
		}
	}
	return (0);
}
