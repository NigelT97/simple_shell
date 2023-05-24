
#include "shell.h"
/**
 * env_shell - prints current environment
 * @args: array
 * @fv: pointer
 * Return: result
 */
int env_shell(char **args, char __attribute__((__unused__)) **fv)
{
	int x;
	char newln = '\n';

	if (!environ)
		return (-1);

	for (x = 0; environ[x]; x++)
	{
		write(STDOUT_FILENO, environ[x], _strlen(environ[x]));
		write(STDOUT_FILENO, &newln, 1);
	}
	(void)args;
	return (0);
}
/**
 * unsetenv_shell - deletes environment path
 * @args: array
 * @fv: pointer
 * Return: result
 */
int unsetenv_shell(char **args, char __attribute__((__unused__)) **fv)
{
	char **envV, **ne;
	size_t size;
	int x1, x2;

	if (!args[0])
		return (create_error(args, -1));
	envV = _getenv(args[0]);
	if (!envV)
		return (0);
	for (size = 0; environ[size]; size++)
		continue;
	ne = malloc(sizeof(char *) * size);
	if (!ne)
		return (create_error(args, -1));
	for (x1 = 0, x2 = 0; environ[x1]; x1++, x2++)
	{
		if (*envV == environ[x1])
		{
			free(*envV);
		}
		ne[x2] = environ[x1];
	}
	free(environ);
	environ = ne;
	environ[size - 1] = NULL;
	return (0);
}
/**
 * setenv_shell - sets or changes environment path
 * @args: array
 * @fv: pointer
 */
int setenv_shell(char **args, char __attribute__((__unused__)) **fv)
{
	char **envV = NULL, **ne, *nv;
	size_t size;
	int x;

	if (!args[0] || !args[1])
		return (create_error(args, -1));
	nv = malloc(_strlen(args[0]) + 1 + _strlen(args[1]) + 1);
	if (!nv)
		return (create_error(args, -1));
	_strcpy(nv, args[0]);
	_strcat(nv, "=");
	_strcat(nv, args[1]);
	envV = _getenv(args[0]);
	if (envV)
	{
		free(*envV);
		*envV = nv;
		return (0);
	}
	for (size = 0; environ[size]; size++)
		continue;
	ne = malloc(sizeof(char *) * (size + 2));
	if (!ne)
	{
		free(nv);
		return (create_error(args, -1));
	}
	for (x = 0; environ[x]; x++)
		ne[x] = environ[x];
	free(environ);
	environ = ne;
	environ[x] = nv;
	environ[x + 1] = NULL;
	return (0);
}
