#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

#define SPECIF " \t\n"
extern char **environ;


/*builtin_functions*/
void exit_shel(char **cmd, char **argv, int *status, int indx);
void pr_env(char **cmd, int *status);

/* tools_function*/
char *read_line(void);
char **get_token(char *line);
char *_get_path(char *cmd);
char *_getenv(char *var);
int _executer(char **cmd, char **argv, int indx);
void pr_error(char *name, char *cmd, int indx);
int is_builtcmd(char *cmd);
void handl_builtcmd(char **cmd, char **argv, int *status, int indx);

/*string_hundler_functions*/
char *_strdup(const char *s);
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
char *int_asc(int n);
void reverse_str(char *str, int len);
int is_num_positive(char *s);
int _atoi(char *s);

/*memory_functions*/
void freearray(char **ary);

#endif /* _SHELL_H_ */
