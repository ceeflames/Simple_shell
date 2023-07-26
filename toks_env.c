#include "shell.h"
/**
 * _strcmp - compares 2 strings
 * @str1: first string
 * @str2: second string
 *
 * Return: 1 || 0
 */
int _strcmp(char *str1, char *str2)
{
	char *ptr1 = str1, *ptr2 = str2;

	if (!str1 || !str2)
		return (0);
	if (ptr1 && ptr2)
	{
		while (*ptr1 || *ptr2)
		{
			if (*ptr2 != *ptr1)
				return (0);
			ptr1++;
			ptr2++;
		}
	}
	return (1);
}

/**
 * setenv_func - setenv builtin
 * @argtoks: array
 *
 * Return: char
 */
char setenv_func(char **argtoks)
{
	char *env_key = argtoks[1], *env_value = argtoks[2], *env_ptr;
	char **env = environ;
	size_t i = 0, _valuelen = _strlen(env_value), _keylen = _strlen(env_key);

	if (!env_key || !env_value)
		return (0);
	while (env[i])
	{
		if (!(_strncmp(env_key, env[i], _keylen)))
		{
			env_ptr = env[i] + _keylen + 1;
			_strcpy(env_ptr, env_value);
		}
		i++;
	}
	env[i] = malloc(_keylen + _valuelen + 3);
	if (!env[i])
		return (0);
	_strcpy(env[i], env_key);
	_strcat(env[i], "=");
	_strcat(env[i], env_value);
	i++;
	env[i] = NULL;
	return (1);
}
/**
 * interpret_func - interprets tokenized string
 * @arg_cmd: array of command line input tokenized
 *
 * Return: ptr to built-in function
 */
char (*interpret_func(char *arg_cmd))(char **arg)
{
	int i = 0;
	_varfunc interpret_cmd[] = {
		{"setenv", setenv_func},
		{"env", env_func},
		{NULL, NULL}};

	while (interpret_cmd[i].str)
	{
		if ((_strcmp(arg_cmd, interpret_cmd[i].str)))
			return (interpret_cmd[i].func_ptr);
		i++;
	}
	return (interpret_cmd[i].func_ptr);
}
/**
 * exitcheck - exit builtin implementation
 * @argtoks: array
 * @buff: buffer
 * @flag: checks for the return of exit
 *
 * Return: 0
 */
int exitcheck(char **argtoks, char *buff, int *flag)
{
	int i;
	char *err = "./hsh: 1: exit: Illegal number: ";

	if (_strcmp(argtoks[0], "exit"))
	{
		if (argtoks[1] != NULL)
		{
			if (argtoks[1][0] != '_' && is_number(argtoks[1]))
			{
				i = _atoi(argtoks[1]);
				free_buff(argtoks);
				free(buff);
				exit(i);
			}
			else
			{
				write(STDERR_FILENO, err, _strlen(err));
				write(STDERR_FILENO, argtoks[1], _strlen(argtoks[1]));
				write(STDERR_FILENO, "\n", 1);
				free_buff(argtoks);
				free(buff);
				exit(2);
			}
		}
		free(buff);
		free_buff(argtoks);
		*flag = 1;
		return (1);
	}
	return (0);
}
/**
 * _getenv - Value of an environment variable using key
 * @key: key of environment var
 *
 * return: pointer to value key
 */
char *_getenv(char *key)
{
	int i, j, key_len, value_len, k = 0;
	char *value;
	char *var_name;

	if (key == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		key_len = _strlen(key);
		var_name = malloc(key_len + 1);

		if (!var_name)
			return (0);
		for (j = 0; j < key_len; j++)
			var_name[j] = environ[i][j];
		var_name[j++] = '\0';
		if (var_name != NULL && _strcmp(var_name, key) == -1)
		{
			value_len = _strlen(environ[i]);
			value = malloc(value_len + 1);
			if (!value)
				return (0);
			while (j <= value_len)
				value[k++] = environ[i][j++];
			value[k] = '\0';
			free(var_name);
			return (value);
		}
		free(var_name);
	}
	return (NULL);
}
