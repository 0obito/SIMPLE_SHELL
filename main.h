#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

extern char **environ;

char *read_input(void);
char **tokenize(char *line, char *delimiter);
char *_strdup(char *str);
int execution(char **cmd, char **av, int indice, char *line);
void free_ressources(char **cmd);
void free_line(char *line);
char *_getenv(char *name);
int _strcmp(char *str1, char *str2);
char *path_search(char *first_cmd);
void _strcat(char *str1, char *str2);
void _strcp(char *dest, char *str);
int _strlen(char *string);
void _perror(char *nom, char *cmd, int n, char *sms);
int _putchar(char c);
void freeall(char *ptr, char **doubleptr);
void _getfullenv(void);

#endif /* MAIN_H */
