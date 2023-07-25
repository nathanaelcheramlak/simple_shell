#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#define LINE_DELIM " \t\n"
#define SIZE 1024

extern char **environ;

int _putchar(char c);
void prompt(void);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strncmp(char *str1, char *str2, int n);
int _strlen(const char *str);

void remove_space(char *str);
void remove_string(char *str);
int start_w(const char *str, const char *sub, int index);
void exit_builtin(int exit_status);

int error(char *name, char *cmd_name);

int builtin(char *cmd);
int exec(int argc, char **argument, char **av);
int path_ls(char *cmd2, int ac, char **av);
int path_ls_bin(char *cmd, char **av);
void print_env(void);

#endif
