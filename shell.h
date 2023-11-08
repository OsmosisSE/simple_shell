#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024 /* A macro for the buffer size */
#define TOK_BUFSIZE 128 /* A macro for the token buffer size */
#define TOK_DELIM " \t\r\n\a" /* A macro defining delimiters for tokeniztion */

/* Points to an array of pointers to strings called the "environment" */
extern char **environ;

/**
 * struct data - struct that contains all relevant data on runtime.
 * @av: argument vector.
 * @input: command line written by the user.
 * @args: tokens of the command line.
 * @status: last status of the shell.
 * @counter: lines counter.
 * @_environ: environment variable.
 * @pid: Process ID of the shell.
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: Single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list.
 * @line: command line.
 * @next: next node.
 * Description: single linked list to store command lines.
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables.
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

/**
 * struct builtin_s - Builtin struct for command args.
 * @name: the name of the command bultin i.e cd, exit, env.
 * @if: data type pointer function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/* hv_main.c */
void free_data(data_shell *datash);
void set_data(data_shell *datash, char **av);
int main(int ac, char **av);
char *without_comment(char *in);
void shell_loop(data_shell *datash);

/* hv_shell_input_utilities.c */
char *read_line(int *i_eof);
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
void get_sigint(int sig);
int get_help(data_shell *datash);

#endif /* _SHELL_H_ */
