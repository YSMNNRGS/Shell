shell: main.c parser.c executor.c builtins.c
	gcc main.c parser.c executor.c builtins.c -o shell

clean:
	rm -f shell
