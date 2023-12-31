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

/* read_line.c */
char *read_line(int *i_eof);

/* get_sigint.c */
void get_sigint(int sig);

/* get_help.c */
int get_help(data_shell *datash);

/* hv_shell_input_utilities.c */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

/* hv_help_function.c */
void hv_help_general(void);
void hv_help_setenv(void);
void hv_help_env(void);
void hv_help_unsetenv(void);

/* hv_help_function2.c */
void hv_help(void);
void hv_help_exit(void);
void hv_help_cd(void);
void hv_help_alias(void);

/* hv_command_parser.c */
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

/* hv_variable_replacement.c */
void check_env(r_var **h, char *in, data_shell *data);
int check_vars(r_var **h, char *in, char *st, data_shell *data);
char *replaced_input(r_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, data_shell *datash);

/* hv_command_executor1.c */
int exec_line(data_shell *datash);
int (*get_builtin(char *cmd))(data_shell *);
int get_error(data_shell *datash, int eval);
int exit_shell(data_shell *datash);

/* hv_command_executor2.c */
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

/* hv_error_messages1.c */
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);

/* hv_error_messages2.c */
char *error_exit_shell(data_shell *datash);
char *error_env(data_shell *datash);
char *error_path_126(data_shell *datash);

/* hv_list_opearations1.c */
sep_list *add_sep_node_end(sep_list **head, char sep);
line_list *add_line_node_end(line_list **head, char *line);
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval);

/* hv_list_operations2.c */
void free_sep_list(sep_list **head);
void free_line_list(line_list **head);
void free_rvar_list(r_var **head);

/* hv_memory_operations.c */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
void _memcpy(void *newptr, const void *ptr, unsigned int size);

/* hv_conversion_operations.c */
int get_len(int n);
char *hv_itoa(int n);
int _atoi(char *s);

/* hv_string_operations1.c */
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);

/* hv_string_operations2.c */
int _strspn(char *s, char *accept);
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);

/* hv_string_operations3.c */
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
void rev_string(char *s);

/* hv_env_operations1.c */
char *copy_info(char *name, char *value);
char *_getenv(const char *name, char **_environ);
void set_env(char *name, char *value, data_shell *datash);

/* hv_env_opearations2.c */
int _env(data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);
int cmp_env_name(const char *nenv, const char *name);

/* hv_syntax_check.c */
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);
int check_syntax_error(data_shell *datash, char *input);

/* hv_cd_commands.c */
void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);

/* cd_shell.c */
int cd_shell(data_shell *datash);


#endif /* _SHELL_H_ */
