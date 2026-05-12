#ifndef BUILTINS_H
#define BUILTINS_H

int is_builtin(char *command);
void run_builtin(char **args);
void add_to_history(char *command);
void show_history();

#endif
