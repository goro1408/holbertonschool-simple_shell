#ifndef SHELL_H
#define SHELL_H

/* ======= LIBRARIES ======= */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* ======= GLOBAL VARIABLES ======= */

extern char **environ;

/* ======= PROTOTYPES ======= */

void prompt(void);
size_t _strcspn(const char *s, const char *accept);
char *readCommand();
char **strTokens(char *command);
int executeCommand(char **array);
int check_exit(char *command);

#endif
