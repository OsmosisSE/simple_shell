#include "shell.h"

/**
* hv_help_general - Displays general help information.
* Return: No return value.
*/
void hv_help_general(void)
{
	char *help = "^-^ bash, version 1.0(1) - release\n";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "These commands are defined internally, Type 'help' to see the list.";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Type 'help name' to find out more about the function 'name'.\n\n";
	write(STDOUT_FILENO, help, _strlen(help));
	help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
* hv_help_setenv - Displays help information for the builtin 'setenv'.
* Return: No return value.
*/
void hv_help_setenv(void)
{
	char *help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "int replace)\n\t";
	write(STDOUT_FILENO, help, _strlen(help));
	help = "Add a new definition to the environment.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
* hv_help_env - Displays help information for the builtin 'env'.
* Return: No return value.
*/
void hv_help_env(void)
{
	char *help  =  "env : env[option][name=value][command[args]]\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Print the environment of the shell.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}

/**
* hv_help_unsetenv - Displays help information for the builtin 'unsetenv'.
* Return: No return value.
*/
void hv_help_unsetenv(void)
{
	char *help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, help, _strlen(help));
	help = "Remove an entry completely from the environment.\n";
	write(STDOUT_FILENO, help, _strlen(help));
}
