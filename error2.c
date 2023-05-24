#include "shell.h"

/**
 * error_env - error message
 * @args: array
 * Return: result
 */
char *error_env(char **args)
{
	char *err, *strhist;
	int ln;

	strhist = _itoa(hist);
	if (!strhist)
		return (NULL);
	args--;
	ln = _strlen(name) + _strlen(strhist) + _strlen(args[0]) + 45;
	err = malloc(sizeof(char) * (ln + 1));
	if (!err)
	{
		free(strhist);
		return (NULL);
	}
	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, strhist);
	_strcat(err, ": ");
	_strcat(err, args[0]);
	_strcat(err, ": Unable to add/remove\n");
	free(strhist);
	return (err);
}
/**
 * error_1 - error message
 * @args: array
 * Return: result
 */
char *error_1(char **args)
{
	char *err;
	int ln;

	ln = _strlen(name) + _strlen(args[0]) + 13;
	err = malloc(sizeof(char) * (ln + 1));
	if (!err)
	{
		return (NULL);
	}
	_strcpy(err, "alias: ");
	_strcat(err, args[0]);
	_strcat(err, ": Not found\n");
	return (err);
}
/**
 * error_2_exit - error message
 * @args: array
 * Return: result
 */
char *error_2_exit(char **args)
{
	char *err, *strhist;
	int ln;

	strhist = _itoa(hist);
	if (!strhist)
		return (NULL);
	ln = _strlen(name) + _strlen(strhist) + _strlen(args[0]) + 27;
	err = malloc(sizeof(char) * (ln + 1));
	if (!err)
	{
		free(strhist);
		return (NULL);
	}
	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, strhist);
	_strcat(err, ": exit: illegat number: ");
	_strcat(err, args[0]);
	_strcat(err, "\n");
	free(strhist);
	return (err);
}
/**
 * error_2_cd - error message
 * @args: array
 * Return: results
 */
char *error_2_cd(char **args)
{
	char *err, *strhist;
	int ln;

	strhist = _itoa(hist);
	if (!strhist)
		return (NULL);
	if (args[0][0] == '-')
		args[0][2] = '\0';
	ln = _strlen(name) + _strlen(strhist) + _strlen(args[0]) + 24;
	err = malloc(sizeof(char) * (ln + 1));
	if (!err)
	{
		free(strhist);
		return (NULL);
	}
	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, strhist);
	if (args[0][0] == '-')
		_strcat(err, ": cd: illegal option ");
	else
		_strcat(err, ": cd: can't cd to ");
	_strcat(err, args[0]);
	_strcat(err, "\n");
	free(strhist);
	return (err);
}
/**
 * error_2_syntax - error
 * @args: array
 * Return: result
 */
char *error_2_syntax(char **args)
{
	char *err, *strhist;
	int ln;

	strhist = _itoa(hist);
	if (!strhist)
		return (NULL);
	ln = _strlen(name) + _strlen(strhist) + _strlen(args[0]) + 33;
	err = malloc(sizeof(char) * (ln + 1));
	if (!err)
	{
		free(strhist);
		return (NULL);
	}
	_strcpy(err, name);
	_strcat(err, ": ");
	_strcat(err, strhist);
	_strcat(err, ": syntax error: \"");
	_strcat(err, args[0]);
	_strcat(err, "\" unexpected\n");
	free(strhist);
	return (err);
}
