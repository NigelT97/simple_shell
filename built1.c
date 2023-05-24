#include "shell.h"
/**
 * get_b - matches command
 * @command: command match
 * Return: a pointer
 */
int (*get_b(char *command))(char **args, char **fv)
{
	t_built fun[] = {
		{ "exit", exit_shell},
		{ "env", env_shell},
		{ "setenv", setenv_shell},
		{ "unsetenv", unsetenv_shell},
		{ "alias", alias_shellby},
		{ "cd", cd_shell},
		{ "help", help_shell},
		{NULL, NULL}
	};
	int i;

	for (i = 0; fun[i].name; i++)
	{
		if (_strcmp(fun[i].name, command) == 0)
			break;
	}
	return (fun[i].f);
}
/**
 * cd_shell - change directory
 * @args: array
 * @fv: pointer
 * Return: outcome
 */
int cd_shell(char **args, char __attribute__((__unused__)) **fv)
{
	char **di, *nl = "\n";
	char *opwd = NULL, *pwd = NULL;
	struct stat dir;

	opwd = getcwd(opwd, 0);
	if (!opwd)
		return (-1);
	if (args[0])
	{
		if (*(args[0]) == '-' || _strcmp(args[0], "--") == 0)
		{
			if ((args[0][1] == '-' && args[0][2] == '\0') ||
					args[0][1] == '\0')
			{
				if (_getenv("OLDPWD") != NULL)
					(chdir(*_getenv("OLDPWD") + 7));
			}
			else
			{
				free(opwd);
				return (create_error(args, 2));
			}
		}
		else
		{
			if (stat(args[0], &dir) == 0 && S_ISDIR(dir.st_mode)
					&& ((dir.st_mode & S_IXUSR) != 0))
				chdir(args[0]);
			else
			{
				free(opwd);
				return (create_error(args, 2));
			}
		}
	}
	else
	{
		if (_getenv("HOME") != NULL)
			chdir(*(_getenv("HOME")) + 5);
	}
	pwd = getcwd(pwd, 0);
	if (!pwd)
		return (-1);
	di = malloc(sizeof(char *) * 2);
	if (!di)
		return (-1);

	di[0] = "OLDPWD";
	di[1] = opwd;
	if (setenv_shell(di, di) == -1)
		return (-1);
	di[0] = "PWD";
	di[1] = pwd;
	if (setenv_shell(di, di) == -1)
		return (-1);
	if (args[0] && args[0][0] == '-' && args[0][1] != '-')
	{
		write(STDOUT_FILENO, pwd, _strlen(pwd));
		write(STDOUT_FILENO, nl, 1);
	}
	free(opwd);
	free(pwd);
	free(di);
	return (0);
}
/**
 * exit_shell - terminate programme
 * @args: arguments
 * @fv: pointer
 * Return:result
 */
int exit_shell(char **args, char **fv)
{
	int i, ln = 10;
	unsigned int nm = 0, max = 1 << (sizeof(int) * 8 - 1);

	if (args[0])
	{
		if (args[0][0] == '+')
		{
			i = 1;
			ln++;
		}
		for (; args[0][i]; i++)
		{
			if (i <= ln && args[0][i] >= '0' && args[0][i] <= '9')
				nm = (nm * 10) + (args[0][i] - '0');
			else
				return (create_error(--args, 2));
		}
	}
	else
		return (-3);
	if (nm > max - 1)
		return (create_error(--args, 2));
	args -= 1;
	free_args(args, fv);
	free_env();
	free_alias_list(aliases);
	exit(nm);
}
/**
 * help_shell - displays helpful info
 * @args: array
 * @fv: pointer
 * Return: result
 */
int help_shell(char **args, char __attribute__((__unused__)) **fv)
{
	if (!args[0])
		help_all();
	else if (_strcmp(args[0], "alias") == 0)
		help_alias();
	else if (_strcmp(args[0], "exit") == 0)
		help_exit();
	else if (_strcmp(args[0], "unsetenv") == 0)
		help_unsetenv();
	else if (_strcmp(args[0], "setenv") == 0)
		help_setenv();
	else if (_strcmp(args[0], "cd") == 0)
		help_cd();
	else if (_strcmp(args[0], "env") == 0)
		help_env();
	else if (_strcmp(args[0], "help") == 0)
		help_help();
	else
		write(STDERR_FILENO, name, _strlen(name));
	return (0);
}

