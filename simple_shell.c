#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 */
int main(int argc, char **argv)
{
    char *command = NULL;
    char *path;
    char **array;
	size_t n = 0;
	ssize_t nread;


	(void)argc;

    while (1)
    {
        prompt();
		
		nread = getline(&command, &n, stdin);
		command[_strcspn(command, "\n")] = '\0';
		if (nread == -1)
		{
			exit(0);
		}
		
		array = strTokens(command);
        path = get_file_path(array[0]);
		check_exit(command);
        executeCommand(array, argv);
    }

    free(path);
    free(command);
    return 0;
}

