#include "shell.h"
/**
 * _getenv - gets an environment variable
 * @var: name of env
 * Return: pointer or NULL
 */
char **_getenv(const char *var)
{
	int x, ln;

	ln = _strlen(var);
	for (x = 0; environ[x]; x++)
	{
		if (_strncmp(var, environ[x], ln) == 0)
			return (&environ[x]);
	}
	return (NULL);
}
/**
 * free_env - frees environment copy
 */
void free_env(void)
{
	int x;

	for (x = 0; environ[x]; x++)
		free(environ[x]);
	free(environ);
}
/**
 * _copyenv - copy of environment
 * Return: result
 */
char **_copyenv(void)
{
	char **ne;
	size_t size;
	int x;

	for (size = 0; environ[size]; size++)
		continue;
	ne = malloc(sizeof(char *) * (size + 1));
	if (!ne)
		return (NULL);
	for (x = 0; environ[x]; x++)
	{
		ne[x] = malloc(_strlen(environ[x]) + 1);
		if (!ne[x])
		{
			for (x--; x >= 0; x--)
				free(ne[x]);
			free(ne);
			return (NULL);
		}
		_strcpy(ne[x], environ[x]);
	}
	ne[x] = NULL;
	return (ne);
}
