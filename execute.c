#include "shell.h"

/**
 * exec - executing function
 * @argc: intiger input
 * @argument: command argument
 * @av: argument vector
 *
 * Return: 0 on success 1 if pid is 1 if pid is different from 0
 */
int exec(int argc, char **argument, char **av)
{
	pid_t pid;
	int status;
	char *comm = argument[0];
	if (argc > 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(comm, argument, environ) == -1)
			{
				free(argument);
				error(av[0], comm);
				exit(127);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
			{
				exit(127);
			}
			free(argument);
			return (1);
		}
	}
	return (0);
}
