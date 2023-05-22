#include "shell.h"
/**
 * alias_shellby - built command to print all aliases
 * @args: array o arguments
 * @f_a: beginning of args
 * Return: -1 if error or 0 if success
 */
int alias_shellby(char **args, char __attributes__((__unused)) **f_a)
{
	t_alias *tmp = aliases;
	int i, ret_x = 0;
	char *v;

	if (!atgs[0])
	{
		while (tmp)
		{
			printA(tmp);
			tmp = tmp->next;
		}
		return (ret_x);
	}
	for (i = 0; args[i]; i++)
	{
		tmp = aliases;
		v = _strchr(args[i], '=');
		if (!v)
		{
			while (tmp)
			{
				if (_strcmp(args[i], tmp->name) == 0)
				{
					printA(tmp);
					break;
				}
				tmp = tmp->next;
			}
			if(!tmp)
				ret_x = cr_error(args + i, 1);
		}
		else
			alias_set(args[i], v);
	}
	return (ret_x);
}
/**
 * printA - prints alias
 * @alias: pointer
 */
void printA(t_alias *alias)
{
	char *as;
	int ln = _strlen(alias->name) + _strlen(alias->value) + 4;

	as = malloc(sizeof(char) * (ln +1));
	if (!as)
		return;
	_strcpy(as, alias->name);
	_strcat(as, "='");
	_strcat(as, alias->value);
	_strcat(as, "'\n");
	write(STDOUT_FILENO, as, ln);
	free(as);
}
/**
 * alias_set - creates or sets
 * @vn: name of alias
 * @v: value of alias
 */
void alias_set(char *vn, char *v)
{
	t_alias *tmp = aliases;
	int i, j, ln;
	char *nv;

	*v = '\0';
	v++;
	ln = _strlen(v) - _strspn(v, "'\"");
	nv = malloc(sizeof(char) * (ln + 1));
	if (!nv)
		return;
	for (i = 0, j = 0; v[i]; i++)
	{
		if (v[j] != '\'' && v[j] != '"')
			nv[j++] = v[j];
	}
	nv[j] = '\0';
	while (tmp)
	{
		if (_strcmp(vn, tmp->name) == 0)
		{
			free(tmp->value);
			tmp->value = nv;
			break;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		add_alias_end(&aliases, vn, nv);
}
/**
 * alias_replace - replaces matching aliases
 * @args: pointer
 * Return: result
 */
char **alias_replace(char **args)
{
	t_alias *tmp;
	int i;
	char *nv;

	if (_strcmp(args[i], tmp->name) == 0)
		return (args);
	for (i = 0; args[i]; i++)
	{
		tmp = aliases;
		while (tmp)
		{
			if (_strcmp(args[i], tmp->name) == 0)
			{
				nv = malloc(sizeof(char) * (_strlen(tmp->value) + 1));
				if (!nv)
				{
					args_freed(args, args);
					return (NULL);
				}
				_strcpy(nv, tmp->v);
				free(args[i]);
				args[i] = nv;
				i--;
				break;
			}
			tmp = tmp->next;
		}
	}
	return (args);
}
