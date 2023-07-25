#include "shell.h"

/**
 * builtin - compares exit or env command
 * @cmd: command line from the user
 *
 * Return: errno if exit 1 if print env 2 on success
 */
int builtin(char *cmd)
{
	if (_strncmp(cmd, "exit", 4) == 0)
	{
		return (0);
	}
	if (_strncmp(cmd, "env", 3) == 0)
	{
		print_env();
		return (1);
	}
	return (2);
}
/**
 * print_env - prints environ
 *
 * Return: none
 */
void print_env(void)
{
	int i = 0;
	int j = 0;

	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] != '\0')
		{
			_putchar(environ[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}
