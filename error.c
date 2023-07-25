#include "shell.h"

/**
 * start_w -  checks if the substring starts at a given index in the string
 * @str: string to be compared with sub
 * @sub: string to be compared with str
 * @index: index number
 *
 * Return: 0 or 1
 */
int start_w(const char *str, const char *sub, int index)
{
	int len = _strlen(sub);
	int i;

	for (i = 0; i < len; i++)
	{
		if (str[i + index] != sub[i])
		{
			return (0);
		}
	}
	return (1);
}

/**
 * remove_string - Removes /bin/
 * @str: The string to be edited.
 *
 * Return: None
 */
void remove_string(char *str)
{
	char *sub = "/bin/";
	int len = _strlen(str);
	int sub_len = _strlen(sub);
	int i, j;

	for (i = 0, j = 0; i < len; i++)
	{
		if (start_w(str, sub, i))
		{
			i += sub_len - 1;
		}
		else
		{
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
}

/**
 * error - prints error message.
 * @name: Name of the file.
 * @cmd_name: Command Line.
 *
 * Return: None
 */
void error(char *name, char *cmd_name)
{
	int i;
	char *error = ": not found\n";

	for (i = 0; name[i] != '\0'; i++)
		_putchar(name[i]);
	_putchar(':');
	_putchar(' ');
	_putchar('1');

	_putchar(':');
	_putchar(' ');
	remove_string(cmd_name);
	for (i = 0; cmd_name[i] != '\0'; i++)
		_putchar(cmd_name[i]);
	for (i = 0; error[i] != '\0'; i++)
		_putchar(error[i]);
}
