#include "shell.h"
/**
 * _putchar - prints a char to stdout
 * @c: char
 *
 * Return: 1 (successful) -1 (error)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _put - prints a string
 * @str: string
 *
 * Return: 0
 */
int _put(char *str)
{
	int n = 0;

	while (str[n])
	{
		_putchar(str[n]);
		n++;
	}
	return (0);
}
/**
 * getline_check - the return value of getline
 * @i: return value
 * @buff: buffer
 */
void getline_check(int i, char *buff)
{
	if (i == -1)
	{
		free(buff);
	}
}

