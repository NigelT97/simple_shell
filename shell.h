#ifndef SHELL_H
#define SHELL_H

/**
* File: shell.h
* Auth: Calvin Kudiwapfava
*       Nigel Masiyazi-Ngorima
*/

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
	char *name;
	int (*f)(char **argv, char **fv);
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
char *_itoa(int n);
char *error_126(char **args);
char *error_127(char **args);
char *error_env(char **args);
char *error_1(char **args);
char *error_2_exit(char **args);
char *error_2_cd(char **args);
char *error_2_syntax(char **args);

int hist;

/* Str functions */
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
int _strspn(char *s, char *accept);


/* Builtins */
int (*get_builtin(char *command))(char **args, char **front);
int shellby_exit(char **args, char **front);
int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);
int shellby_cd(char **args, char __attribute__((__unused__)) **front);
int shellby_alias(char **args, char __attribute__((__unused__)) **front);
int shellby_help(char **args, char __attribute__((__unused__)) **front);

typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/* Linkedlist */
t_alias *add_alias_end(t_alias **head, char *name, char *value);
void free_alias_list(t_alias *head);
list_t *add_node_end(list_t **head, char *dir);
void free_list(list_t *head);

void help_unsetenv(void);
void help_history(void);
void help_help(void);
void help_all(void);
void help_alias(void);
void help_env(void);
void help_setenv(void);
void help_cd(void);
void help_exit(void);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int proc_file_commands(char *file_path, int *exe_ret);

/*files missed*/
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);
void free_args(char **args, char **front);
char *get_pid(void);
char *get_env_value(char *beginning, int len);
void variable_replacement(char **args, int *exe_ret);
int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);
void handle_line(char **line, ssize_t read);
ssize_t get_new_len(char *line);
void logical_ops(char *line, ssize_t *new_len);
char *get_location(char *command);
char *fill_path_dir(char *path);
list_t *get_path_dir(char *path);
int execute(char **args, char **front);
char **replace_aliases(char **args);
int cant_open(char *file_path);

#endif
