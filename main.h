#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

extern char **environ;

char *read_input(void);
char **tokenize(char *line);
char *_strdup(char *str);
int execution(char *command[], char *argv[], char *line);
void free_ressources(char **command);
void free_line(char *line);
char *_getenv(const char *name);

#endif /* MAIN_H */
