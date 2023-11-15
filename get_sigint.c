#include "shell.h"

/**
 * get_sigint - Signal handler for Ctrl+C (SIGINT)
 * @sig: The signal number to be handled (ignored).
 *
 * This function handles the Ctrl+C (SIGINT) signal when it is sent to the
 * shell process. It ensures that a newline is printed, and the prompt is
 * displayed again, allowing the user to continue entering commands.
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
