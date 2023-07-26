#include "shell.h"

/**
 * _handlesignal - Signal handler
 * @sig: signal
 */

void _handlesignal(int sig)
{
	(void)sig;

	signal(SIGINT, _handlesignal);
	free(buff);
	_putchar(10);
}
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 * @env: environment
 *
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	int j = 0, flags = 0, _exit = 0, _terminal = isatty(STDIN_FILENO), i;
	size_t _arr = 0;
	char *s = "$ ", **a = NULL, (*h)(char **a), *pt = NULL, *fl = argv[0];
	(void)argc;

	while (1)
	{
		if (_terminal)
			_put(s);
		j = getline(&buff, &_arr, stdin);
		getline_check(j, buff);
		if (buffchecker(buff))
			continue;
		buff[j - 1] = '\0';
		a = _parse(buff);
		if (!a[0])
		{
			free_buff(a);
			continue;
		}
		pt = path(a[0]);
		i = exitcheck(a, buff, &flags);
		if (i)
			return (flags ? _exit : i);
		if (!pt)
		{
			h = interpret_func(a[0]);
			if (h)
				h(a);
			else
				perror(fl);
		}
		else
			_exit = exec(pt, a, env);
		free(pt);
		free_buff(a);
	}
	free(buff);
	return (0);
}
/**
 * pid_return_value - Expand $$ and $?
 * @patt: pattern
 *
 * Return: pid || return value
 */
int pid_return_value(char *patt)
{
	if (_strcmp(patt, "$$"))
	{
		return (getppid());
	}
	else if (_strcmp(patt, "$?"))
	{
		return (0);
	}
	return (1);
}
