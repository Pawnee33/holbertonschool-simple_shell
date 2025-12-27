#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

void print_pid(void);
void print_ppid(void);
char *get_line(void);
char **str_tok(char *line);
void fork_execv_wait(char **args, char **env);
char *_which(char *order, char **env);

#endif
