#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "builtins.h"

#define MAX_HISTORY 100
#define MAX_COMMAND_LENGTH 1024

char history[MAX_HISTORY][MAX_COMMAND_LENGTH];
int history_count = 0;

int is_builtin(char *command) {
    if (strcmp(command, "cd") == 0) return 1;
    if (strcmp(command, "exit") == 0) return 1;
    if (strcmp(command, "help") == 0) return 1;
    if (strcmp(command, "history") == 0) return 1;

    return 0;
}

void run_builtin(char **args) {
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            printf("cd: missing directory\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("cd failed");
            }
        }
    }

    else if (strcmp(args[0], "exit") == 0) {
        printf("Exiting shell...\n");
        exit(0);
    }

    else if (strcmp(args[0], "help") == 0) {
        printf("Simple Shell Help\n");
        printf("Built-in commands:\n");
        printf("cd <directory>  - change directory\n");
        printf("exit            - exit shell\n");
        printf("help            - show help\n");
        printf("history         - show command history\n");
        printf("External commands supported: ls, pwd, date, cat, mkdir, touch, etc.\n");
    }

    else if (strcmp(args[0], "history") == 0) {
        show_history();
    }
}

void add_to_history(char *command) {
    if (history_count < MAX_HISTORY) {
        strcpy(history[history_count], command);
        history_count++;
    }
}

void show_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d %s\n", i + 1, history[i]);
    }
}
