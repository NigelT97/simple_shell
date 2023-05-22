#ifndef SHELL_H
#define SHELL_H

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>

/**
 * struct alias_s - new struct aliases
 * @name: names
 * @value: values
 * @next: pointer
 */
typedef struct alias_s
{
	char *value;
	char *name;
	struct alias_s *next;
} t_alias;
t_alias *aliases;

/* abuilt c folder */
int alias_shellby(char **args, char __attribute__((__unused__)) **f_a);
void printA(t_alias *alias);
void alias_set(char *vn, char *v);
char **alias_replace(char **args);

/*built1 c folder */
int (*get_b(char *command))(char **args, char **fv);
int cd_shell(char **atgs, char __attribute__((__unused__)) **fv);
int exit_shell(char **args, char **fv);
int help_shell(char **args, char __attribute__((__unused__)) **fv);

typedef struct t_builtn
{
	int (*f)(char **argv, char **fv);
	char *name;
} t_built;

#endif
