#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
extern char **environ;
char *buff;
#define MAXSIZE 50


int _putchar(char c);
int _put(char *str);
void getline_check(int i, char *buff);
void _handlesignal(int sig);

typedef struct var
{
	char *str;
	char (*func_ptr)(char **arg);
} _varfunc;

typedef struct env_var
{
	char *key;
	char equals;
	char *value;
	struct env_var *next;
} env_list;

int buffchecker(char *buff);
int _atoi(char *str);
int _strlen(char *str);

char *_skipspace(char *str);
int word_len(char *str);
char *_strcat(char *str1, char *str2);
char *_strcpy(char *str1, char *str2);
char *_strcpyp(char *str1, char *str2);
int words_num(char *str);
int is_number(char *str);
char **_parse(char *user_input);
void free_buff(char **buff);
int _readcheck(int n, char *buff, int _terminal);
int exec(char *file_path, char **argtoks, char **env);
char *path(char *cmd);
char setenv_func(char **argtoks);
char (*interpret_func(char *arg_cmd))(char **arg);
int exitcheck(char **argtoks, char *buff, int *flag);
int _strcmp(char *str1, char *str2);
int _strncmp(char *str1, char *str2, size_t len);
char *_getenv(char *key);
char *_strtok(char *str, char *delim);
char env_func(char **arg);
char *_strdup(char *str);

int main(int argc, char **argv, char **env);
int pid_return_value(char *patt);
#endif
