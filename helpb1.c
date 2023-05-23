#include "shell.h"
/**
 * help_alias - info on alias
 */
void help_alias(void)
{
	char *msg = "alias: alias [NAME[='VALUE'] ...]\n\tHandles aliases.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "\n\talias: Prints a list of all aliases, one per line,";
	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " in the format NAME = 'VALUE'\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 * help_all - all possible commands
 */
void help_all(void)
{
	char *msg = "Shellby\nThese shell commands are defined internally.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = "Type 'help' to see this list\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 * help_help - display 
 */
void help_help(void)
{
	char *msg = "help: help\n\tSee all possible Shellby builtin commands.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 * help_cd
 */
void help_cd(void)
{
	char *msg = "cd: cd [Directory]\n\tChanges the current directory of the";

	write(STDOUT_FILENO, msg, _strlen(msg));
	msg = " process to Directory.\n";
	write(STDOUT_FILENO, msg, _strlen(msg));
}
/**
 * help_exit
 */
void help_exit(void)
{
	char *msg = "exit: exit [STATUS]\n\tExits the shell.\n";

	write(STDOUT_FILENO, msg, _strlen(msg));
}
