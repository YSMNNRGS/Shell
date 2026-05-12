#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "executor.h"
#include "builtins.h"

#define MAX_INPUT 1024
#define MAX_ARGS 100

int main() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];

    while (1) {
        printf("myshell> ");

        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            break;
        }

        remove_newline(input);

        if (strlen(input) == 0) {
            continue;
        }

        add_to_history(input);

        int arg_count = parse_input(input, args);

        if (arg_count == 0) {
            continue;
        }

        if (is_builtin(args[0])) {
            run_builtin(args);
        } else {
            execute_command(args);
        }
    }

    return 0;
}
