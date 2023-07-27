#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#define BUFSIZE 50
extern char **environ;
char *buf;
typedef struct var
{
	char *str;
	char (*func_ptr)(char **arg);
} var_func;
typedef struct env_var
{
	char *key;
	char equals;
	char *value;
	struct env_var *next;
} env_list;
char *skip_spaces(char *str);
char **parse_input(char *user_input);
void getlinecheck(int n, char *buf);
char *path(char *command);
void sig_handler(int signum);
char *read_input(void);
char *_strcat(char *str1, char *str2);
char *_strcpyp(char *str1, char *str2);
char *_strcpy(char *str1, char *str2);
int _strcmp(char *str1, char *str2);
int wordlen(char *str);
int _strlen(char *str);
int num_words(char *str);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char (*interpret_func(char *arg_command))(char **arg);
int _strcmp(char *str1, char *str2);
char *_strdup(char *str);
char *_getenv(char *key);
int _atoi(char *s);
char *_strtok(char *str, char *delim);
void free_buf(char **buf);
int bufcheck(char *buf);
int readcheck(int n, char *buf, int is_terminal);
int exitcheck(char **arg_tokens, char *buf, int *flag);
int execute(char *filepath, char **arg_tokens, char **env);
int _putchar(char c);
int _puts(char *str);
char setenv_func(char **arg);
char env_func(char **arg);
int _isnumber(char *c);
#endif
