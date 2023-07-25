#include "shell.h"

/**
 * _putchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}

/**
 * prompt - prompts '$'
 *
 * Return: none.
 */
void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * _strcpy - copies string from src and paste it to dest
 * @src: The string to be copied
 * @dest: The string src going to be pasted
 *
 * Return: The pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int count = 0;

	while (count >= 0)
	{
		dest[count] = src[count];
		if (src[count] == '\0')
			break;
		count++;
	}
	return (dest);
}
/**
 * _strcat - concatenates src to dest
 * @src: source string
 * @dest: destination string
 *
 * Return: The pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int count = 0, count2 = 0;

	while (dest[count] != '\0')
		count++;

	while (count2 >= 0)
	{
		dest[count] = src[count2];
		if (src[count2] == '\0')
			break;
		count++;
		count2++;
	}
	return (dest);
}
/**
 * _strncmp - compares between str1 and str2
 * @str1: First string to be compared
 * @str2: Second string to be compared
 * @n: Determines the maximum number of character to be compared
 *
 * Return: posetive if str1 is greater than str2
 * negative if str1 is less than str2
 * 0 if bothe are equal
 */
int _strncmp(char *str1, char *str2, int n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
			return ((*str1) - (*str2));

		else if (*str1 == '\0')
			return (0);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
