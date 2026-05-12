#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "executor.h"

void execute_command(char **args) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return;
    }

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Command failed");
            exit(1);
        }
    } else {
        wait(NULL);
    }
}
