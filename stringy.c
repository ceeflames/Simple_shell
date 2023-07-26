#include "shell.h"
/**
 * _strcpyp - copies word to buffer
 * @str1: buff
 * @str2: pointer to word
 *
 * Return: buffer
 */
char *_strcpyp(char *str1, char *str2)
{
	char *ptr1 = str1, *ptr2 = str2;

	while (*ptr2 && *ptr2 != ' ')
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
	}
	*ptr1 = '\0';
	return (str1);
}
/**
 * _strcpy - copies content of str2 to str1
 * @str1: first string
 * @str2: second str
 *
 * Return: str1
 */
char *_strcpy(char *str1, char *str2)
{
	char *ptr1 = str1, *ptr2 = str2;

	while (*ptr2)
	{
		*ptr1 = *ptr2;
		ptr1++;
		ptr2++;
	}
	*ptr1 = '\0';
	return (str1);

}
/**
 * words_num - The number of words in a string
 * @str: string
 *
 * Return: number of words
 */
int words_num(char *str)
{
	int i = 0;
	char *ptr;

	if (str)
	{
		ptr = str;
		while (*ptr)
		{
			if (*ptr != ' ' && (*(ptr + 1) == ' ' || *(ptr + 1) == '\0'))
				i++;
			ptr++;
		}
	}
	return (i);
}
/**
 * is_number - checks if a string is a number
 * @str: string
 *
 * Return: 0 || 1
 */
int is_number(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
/**
 * _strncmp - compares strings checking for a match
 * @str1: first string
 * @str2: second string
 * @len: str length
 *
 * Return: 1 || 0 if strings don't match
 */
int _strncmp(char *str1, char *str2, size_t len)
{
	size_t i = 0;
	char *ptr1 = str1, *ptr2 = str2;

	if (ptr1 && ptr2)
	{
		while (i < len)
		{
			if (*ptr2 != *ptr1)
				return (1);
			ptr1++;
			ptr2++;
			i++;
		}
	}
	return (0);
}
