#include "shell.h"

/**
 * hv_help - Display help informationfor the builtin 'help'.
 * Return: No return Value.
 */
void hv_help(void)
{
	char *help = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDisplay information about builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * hv_help_exit - Displays help information for the builtin 'exit'.
 * Return: No return value.
 */
void hv_help_exit(void)
{
	char *help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Exits the shell with a status of N. if N is omitted,";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "the exit status is that of the last command executed\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * hv_help_cd - Display help information for the builtin 'cd'.
 * Return: No return value.
 */
void hv_help_cd(void)
{
	char *help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
 * hv_help_alias - Display help information for the builtin 'alias'.
 * Return: NO return value.
 */
void hv_help_alias(void)
{
	char *help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "\tDefine or display aliases.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
