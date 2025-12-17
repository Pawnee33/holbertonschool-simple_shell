#ifndef _SHELL_H
#define _SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *get_line(void);
char **str_tok(char *line);
void fork_execv_wait(char **args);

#endif
