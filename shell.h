#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/**
 * struct list_path - Linked list containing PATH directories
 * @dir: directory in path
 * @p: pointer to next node
 */
typedef struct list_path
{
	char *dir;
	struct list_path *p;
} list_path;

/**
 * struct mybuild - pointer to function with corresponding buildin command
 * @name: buildin command
 * @func: execute the buildin command
 */
typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

void sig_handler(int sig_num);
int _strlen(char *s);
void _puts(char *str);
int _putchar(char c);
void _EOF(int len, char *buff);
void _isatty(void);
char **splitstring(char *str, const char *delim);
void execute(char **argv);
char *_getenv(const char *name);
char *_strdup(char *str);
char *concat_all(char *name, char *sep, char *value);
void(*checkbuild(char **arv))(char **arv);
list_path *linkpath(char *path);
list_path *add_node_end(list_path **head, char *str);
char *_which(char *filename, list_path *head);
void free_list(list_path *head);
void freearv(char **arv);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
