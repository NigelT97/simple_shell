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

#define END_OF_FILE -2
#define EXIT -3

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
/*built2 c folder */
int env_shell(char **args, char __attribute__((__unused__)) **fv);
int unsetenv_shell(char **args, char __attribute__((__unused__)) **fv);
int setenv_shell(char **args, char __attribute__((__unused__)) **fv);

typedef struct t_builtn
{
	int (*f)(char **argv, char **fv);
	char *name;
} t_built;

extern char **environ;

/*help c folders */
void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);

char *name;

/*env c folders*/
char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/*error c folders*/
int create_error(char **args, int error_value);
int num_len(int n);
char *_itao(int n);
char *error_126(char **args);
char *error_127(char **args);
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);

int hist;


#endif
