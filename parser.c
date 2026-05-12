#include <stdio.h>
#include <string.h>
#include "parser.h"

void remove_newline(char *input) {
    input[strcspn(input, "\n")] = '\0';
}

int parse_input(char *input, char **args) {
    int count = 0;
    char *token = strtok(input, " ");

    while (token != NULL) {
        args[count] = token;
        count++;
        token = strtok(NULL, " ");
    }

    args[count] = NULL;
    return count;
}
