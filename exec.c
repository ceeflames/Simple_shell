#include "shell.h"
/**
 * buffchecker - check if buffer is empty
 * @buff: buffer
 *
 * Return: 0 || 1 if empty
 */
int buffchecker(char *buff)
{
	if (*buff == '\n' || *(_skipspace(buff)) == '\n')
	{
		return (1);
	}
	return (0);
}
/**
 * free_buff - Frees array of command-argument pair
 * @buff: array
 */
void free_buff(char **buff)
{
	int i = 0;

	while (buff[i])
		free(buff[i++]);
	free(buff);
}
/**
 * _readcheck - For checking return value of read
 * @_terminal:l value when input is from stdin || pipe
 * @n: nnumber of bytes
 * @buff: array
 *
 * Return: 1 (successful) || -1 (failure)
 */
int _readcheck(int n, char *buff, int _terminal)
{

	(void)buff;

	if (n <= 0)
	{
		if (n == 0 && _terminal)
			_putchar('\n');
		return (-1);
	}
	return (0);
}
/**
 * exec - command execution
 * @file_path: filepath
 * @argtoks: array of arguments
 * @env: environment variable list
 *
 * Return: 0 (failure) || 1 (successful)
 */
int exec(char *file_path, char **argtoks, char **env)
{

	pid_t my_pid;
	pid_t child_pid;
	int status, exit_status = -1;

	if (file_path)
	{
		my_pid = fork();
		if (my_pid == 0)
		{
			if ((execve(file_path, argtoks, env) == -1))
			{
				perror("execve");
				return (-1);
			}
		}
		else if (my_pid == -1)
		{
			perror("fork");
			return (-1);
		}
		else
		{
			child_pid = waitpid(my_pid, &status, 0);
			if (child_pid == -1)
			{
				perror("waitpid");
				return (-1);
			}

			if (WIFEXITED(status))
                                exit_status = WEXITSTATUS(status);
                        else if (WIFSIGNALED(status))
                                exit_status = WTERMSIG(status);
		}
		return (exit_status);
	}
	return (1);
}
/**
 * _changedir - change directory to path
 * @path: pointer to new path
 *
 * Return: path
 */
char *_changedir(char *path)
{
	char *dir = NULL;

	if (*path == '_')
	{
		dir = _getenv("PWD");
		if (!chdir(dir))
			return (0);
	}
	else
	{
		char *currentpath = getcwd(NULL, 128);

		setenv_func(&currentpath);
		if (!chdir(path))
			return (0);
	}
	return (0);
}
