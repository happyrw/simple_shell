#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <sys/types.h>

void display_prompt(void);
void rwanda_printef(const char *inputmessage, ...);
int toread_inputed_command(char *input_command, size_t command_size);
void executing_inputed_command(const char *command);
int arguments(int argc, char *argv[]);
int tokenisation();
int parent_pid();
int child_pid();

#endif /* Shell_h */
