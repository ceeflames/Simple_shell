#include "shell.h"
/**
 * _skipspace - skips space
 * @str: string
 *
 * Return: ptr to the next character in str
 */
char *_skipspace(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str != ' ')
				break;
			str++;
		}
	}
	return (str);
}

/**
 * _strlen - string length
 * @str: pointer to string
 *
 * Return: string length
 */
int _strlen(char *str)
{
	if (*str == '\0')
		return (0);
	else
		return (1 + _strlen(str + 1));
}

/**
 * _atoi - changes string to integer
 * @str: string ptr
 *
 * Return: int
 */
int _atoi(char *str)
{
	int i, j = 0, n = _strlen(str);
	unsigned int num = 0;

	for (i = 0; i < n; i++)
	{
		if (str[i] == 45)
			j++;
		if (str[i] >= 48 && str[i] < 58)
		{
			num = num * 10 + (str[i] - 48);
			if (!(str[i + 1] >= 48 && str[i + 1] < 58))
				break;
		}
	}
	if (!(j % 2))
		return (num);
	else
		return (-num);
}
/**
 * word_len - length of word in a string
 * @str: string
 *
 * Return: lenght of word
 */
int word_len(char *str)
{
	if (*str == ' ' || !*str)
		return (0);
	return (1 + word_len(str + 1));
}
/**
 * _strcat - cat a string
 * @str1: first string
 * @str2: second string
 *
 * Return: str1
 */
char *_strcat(char *str1, char *str2)
{
	char *ptr1 = str1, *ptr2 = str2;

	while (*ptr1)
		ptr1++;
	_strcpyp(ptr1, ptr2);
	return (str1);
}
