#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 */
int main(int argc, char **argv)
{
	int status = 1;
	int is_interactive = isatty(STDIN_FILENO);
	char *command = NULL;
	char **array;
	(void)argc;
	(void)argv;


	while (status)
	{
		if (is_interactive)
		{
			prompt();
		}
			command = readCommand();
			array = strTokens(command);
			check_exit(command);
			executeCommand(array);
	}
	free(command);
	return (0);
}
