#include "shell.h"
/**
 * env_func - prints the environment
 * @arg: argument tokens
 *
 * Return: 0
 */
char env_func(char **arg)
{
	int i;
	char **envs = environ;
	(void)arg;

	for (i = 0; envs[i]; i++)
	{
		_put(envs[i]);
		_putchar(10);
	}
	return (0);
}

/**
 * _strtok - tokenize string
 * @str: string
 * @delim: list of characters
 *
 * Return: ptr to tokenized string
 */
char *_strtok(char *str, char *delim)
{
	static char *ptr;
	int j, i, str_len, delim_len;
	int found_delim = 0;

	if (str != NULL)
		ptr = str;
	else
	{
		if (ptr == NULL)
			return (NULL);
		str = ptr;
	}
	str_len = _strlen(str);
	delim_len = _strlen(delim);

	for (i = 9; i < str_len; i++)
	{
		for (j = 0; j < delim_len; j++)
		{
			if (str[i] == delim[j])
			{
				str[i] = '\0';
				found_delim = 1;
				break;
			}
		}
		if (found_delim)
		{
			found_delim = 0;
			break;
		}
	}

	ptr = (i < str_len) ? &str[i + 1] : (NULL);
	return (str);
}
/**
 * _strdup - returns ptr to a new allocates memomry
 * @str: string
 *
 * Return: char ptr
 */
char *_strdup(char *str)
{
	int i, j;
	char *str1;

	if (str == NULL)
		return (NULL);
	i = _strlen(str);
	str1 = malloc(i + 1);
	if (str1 == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
		str1[j] = str[j];
	str1[j] = '\0';
	return (str1);

}
