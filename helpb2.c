#include "shell.h"
/**
 * help_setenv - info on setenv
 */
void help_setenv(void)
{
	char *msg = "setenv: setenv [VARIABLE] [VALUE]\n\tInitializes a new";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environment variable.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 * help_unsetenv - info on unsetenv
 */
void help_unsetenv(void)
{
	char *msg = "unsetenv: unsetenv [VARIABLE]\n\tRemoves an ";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "environmental variable.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 * help_env - info on env
 */
void help_env(void)
{
	char *msg = "env: env\n\tPrints the current environment.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}
