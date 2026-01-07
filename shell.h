#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

char *get_line(void);
char **str_tok(char *line);
int fork_execv_wait(char **args, char **env, char *programme);
void print_pid(void);
void print_ppid(void);
char *_which(char *order, char **env);
char *rebuild_path(char *folder, char *order);
char *search_path(char **env);
void print_env(char **env);


#endif
