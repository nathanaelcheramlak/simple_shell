#include "shell.h"

/**
 * path_ls_bin - breaks strings and excute them
 * @cmd: command from the user
 * @av: argument vector
 *
 * Return: 0 on success 1 if exec function returns 1
 */
int path_ls_bin(char *cmd, char **av)
{
	int argc = 0, status = 0;
	char **argv = NULL, *token = NULL;

	argv = malloc(sizeof(char *) * SIZE);

	token = strtok(cmd, LINE_DELIM);
	argv[0] = token;
	while (token)
	{
		argc++;
		token = strtok(NULL, LINE_DELIM);
		argv[argc] = token;
	}
	argv[argc] = NULL;
	status = exec(argc, argv, av);
	if (status == 1)
	{
		return (1);
	}
	free(argv);
	return (0);
}

/**
 * path_ls - breaks strings and excute them
 * @cmd: command from the user
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success 1 if exec function returns 1
 */
int path_ls(char *cmd, int ac __attribute__((unused)), char **av)
{
	int argc = 0, status = 0;
	char **argv2 = NULL, *token = NULL, *cmd2 = NULL;

	cmd2 = malloc(sizeof(char *) * SIZE);

	cmd2 = _strcpy(cmd2, "/bin/");
	cmd2 = _strcat(cmd2, cmd);

	argv2 = malloc(sizeof(char *) * SIZE);

	token = strtok(cmd2, LINE_DELIM);
	argv2[0] = token;
	while (token)
	{
		argc++;
		token = strtok(NULL, LINE_DELIM);
		argv2[argc] = token;
	}
	argv2[argc] = NULL;

	status = exec(argc, argv2, av);
	free(cmd2);

	if (status == 1)
	{
		return (1);
	}

	return (0);
}
