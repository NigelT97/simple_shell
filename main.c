#include "shell.h"
/**
 * execute - opens up child process
 * @args: array
 * @fv: pointers
 * Return: result
 */
int execute(char **args, char **fv)
{
	pid_t childp;
	int flag = 0; rt = 0; sp;
	char *cmds = args[0];

	if (cmds[0] != '/' && cmds[0] != '.')
	{
		flag = 1;
		cmds = get_location(cmds);
	}
	if (!cmds || (access(cmds, F _OK) == -1))
	{
		if (errno == EACCES)
			rt = (create_error(args, 126));
		else
			rt = (create_error(args, 127));
	}
	else
	{
		childp = fork();
		if (childp == -1)
		{
			if (flag)
				free(cmds);
			perror("Error child process:");
			return (1);
		}
		if (childp == 0)
		{
			excve(cmds, args, environ);
			if (errno == EACCES)
				rt = (create_error(args, 126));
			free_env();
			free_args(args, fv);
			free_alias_list(aliases);
			_exit(rt);
		}
		else
		{
			wait(&sp);
			rt = WEXISTATUS(sp);
		}
	}
	if (flag)
		free(cmds);
	return (rt);
}
/**
 * handler_signal - prompt of signal
 * @s: signal
 */
void handler_signal(int s)
{
	char *np = "\n=>$ ";

	(void)s;
	signal(SIGINT, handler_signal);
	write(STDIN_FILENO, np, 5);
}
/**
 * main - UNIX programme
 * @argc: number of arguments
 * @argv: array
 * Return: result;
 */
int main(int argc, char *argv[])
{
	int rt = 0, rtn, exert = &rtn;
	char *np = "=>$ ", *nl = "\n";

	name = argv[0];
	hist = 1;
	aliases = NULL;
	signal(SIGINT, handler_signal);

	*exert = 0;
	environ = _copyenv();
	if (!environ)
		exit(-100);
	if (argc != 1)
	{
		rt = proc_file_commands(argv[1], exert);
		free_env();
		free_alias_list(aliases);
		return (*exert);
	}
	if (!satty(STDIN_FILENO))
	{
		while (rt != END_OF_FILE && rt != EXIT)
			rt = handle_args(exert);
		free_env();
		free_alias_list(aliases);
		return (*exert);
	}
	while (1)
	{
		write(STDOUT_FILENO, np, 4);
		rt = handle_args(exert);
		if (rt == END_OF_FILE || rt == EXIT)
		{
			if (rt = END_OF_FILE)
				write(STDOUT_FILENO, nl, 1);
			free_env();
			free_alias_list(aliases);
			exit(exert);
		}
	}
	free_env();
	free_alias_list(aliases);
	return (*exert);
}
