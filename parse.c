#include "shell.h"
/**
 * _parse - string tokenizer
 * @user_input: str
 *
 * Return: tokenized string
 */
char **_parse(char *user_input)
{
	char **arr = NULL, *start_write = user_input;
	int i = 0, j, len;

	arr = malloc(sizeof(char *) * (words_num(user_input) + 1));

	if (!arr)
		return (0);
	while (*start_write)
	{
		start_write = _skipspace(start_write);
		if (*start_write == '\0' || *start_write == '#')
			break;
		len = word_len(start_write);
		arr[i] = malloc(len + 1);
		if (!arr[i])
		{
			for (j = i; j > 0; j--)
				free(arr[j]);
			free(arr);
			return (0);
		}

		_strcpyp(arr[i], start_write);
		start_write += len;
		i++;
	}
	arr[i] = NULL;
	return (arr);

}
/**
 * path - Path
 * @cmd: redirect path
 *
 * Return: NULL (failure) || path (successful)
 */
char *path(char *cmd)
{
	char *filepath = _getenv("PATH"), *env_path = NULL;
	char *copy_path = _strdup(filepath), *toks = _strtok(copy_path, ":");
	size_t path_len;

	if (!cmd)
		return (NULL);
	while (toks != NULL)
	{
		if (*cmd == '/' || *cmd == '.')
		{
			free(filepath);
			free(copy_path);
			env_path = access(cmd, X_OK) != 0 ? NULL : _strdup(cmd);
			return (env_path);
		}
		path_len = _strlen(toks) + _strlen(cmd) + 2;
		env_path = malloc(path_len);
		if (env_path == NULL)
		{
			free(filepath);
			free(copy_path);
			return (NULL);
		}
		_strcpy(env_path, toks);
		_strcat(env_path, "/");
		_strcat(env_path, cmd);
		if (access(env_path, X_OK) == 0)
		{
			free(filepath);
			free(copy_path);
			return (env_path);
		}
		free(env_path);
		env_path = NULL;
		toks = _strtok(NULL, ":");
	}
	free(copy_path);
	free(filepath);
	return (env_path);
}
