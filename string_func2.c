#include "shell.h"

/**
 * _strlen - counts the number of charactes in string
 * @str: input string to be counted
 *
 * Return: len.
 */
int _strlen(const char *str)
{
	int len = 0;

	if (!str)
		return (len);
	for (len = 0; str[len]; len++)
		;
	return (len);
}

/**
 * remove_space - removes leading or trailing whitespaces from a given command
 * @str: input string from the user
 *
 * Return: none
 */
void remove_space(char *str)
{
	int len = _strlen(str), i, j;
	int start = 0, end = len - 1;

	while (str[start] == ' ' || str[start] == '\t' || str[start] == '\n')
	{
		start++;
	}

	while (end >= start &&
		   (str[end] == ' ' || str[end] == '\t' || str[end] == '\n'))
	{
		end--;
	}

	for (i = 0, j = start; j <= end; i++, j++)
	{
		str[i] = str[j];
	}
	str[i] = '\0';
}
