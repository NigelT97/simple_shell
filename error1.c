#include "shell.h"
/**
 * create_error - custom error
 * @args: array
 * @error_value: value
 * Return: value
 */
int create_error(char **args, int error_value)
{
	char *err;

	switch (error_value)
	{
		case -1:
			err = error_env(args);
			break;
		case 1:
			err = error_1(args);
			break;
		case 2:
			if (*(args[0]) == 'e')
				err = error_2_exit(++args);
			else if (args[0][0] == ';' || args[0][0] == '&' || args[0][0] == '|')
				err = error_2_syntax(args);
			else
				err = error_2_cd(args);
			break;
		case 126:
			err = error_126(args);
			break;
		case 127:
			err = error_127(args);
			break;
	}
	write(STDERR_FILENO, err, _strlen(err));
	if (err)
		free(err);
	return (error_value);
}
/**
 * num_len - counts
 * @n: number
 * Return: result
 */
int num_len(int n)
{
	unsigned int n1;
	int ln = 1;

	if (n < 0)
	{
		ln++;
		n1 = n * -1;
	}
	else
	{
		n1 = n;
	}
	while (n1 > 9)
	{
		ln++;
		n1 /= 10;
	}
	return (ln);
}
/**
 * _itao - converts integer
 * @n: integer
 * Return: result
 */
char *_itoa(int n)
{
	char *buffer;
	unsigned int n1;
	int ln = num_len(n);

	buffer = malloc(sizeof(char) * (ln + 1));
	if (!buffer)
		return (NULL);

	buffer[ln] = '\0';
	if (n < 0)
	{
		n1 = n * -1;
		buffer[0] = '-';
	}
	else
	{
		n1 = n;
	}

	ln--;
	do {
		buffer[ln] = (n1 % 10) + '0';
		n1 /= 10;
		ln --;
	} while (n1 > 0);
	return (buffer);
}
/**
 * error_126 - error message
 * @args: array
 * Return: result
 */
char *error_126(char **args)
{
	char *err, *strhist;
	int ln;

	strhist = _itoa(hist);
	if (!strhist)
		return (NULL);
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
	_strcat(err, ": ");
	_strcat(err, ": Permission denied\n");
	free(strhist);
	return (err);
}
/**
 * error_127 - error message
 * @args: array
 * Return: result
 */
char *error_127(char **args)
{
	char *err, *strhist;
	int ln;
	
	strhist = _itoa(hist);
	if (!strhist)
		return (NULL);
	ln = _strlen(name) + _strlen(strhist) + _strlen(args[0]) + 16;
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
	_strcat(err, ": not found\n");
	free(strhist);
	return (err);
}
