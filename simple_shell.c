#include "shell.h"

/**
 * main - Simple-Shell.
 * @ac: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int ac, char **argv)
{
	char *command = NULL, *av[2];
	int status;
	size_t n = 0;
	pid_t pid;
	(void)ac;

	while (1)
	{
		prompt();

		getline(&command, &n, stdin);
		command[strcspn(command, "\n")] = '\0';

		if (command[0] == '\0')
		{
			continue;
		}

		pid = fork();
		if (pid < 0)
		{
			fprintf(stderr, "%s\n", argv[0]);
		}
		else if (pid == 0)
		{
			av[0] = command;
			av[1] = NULL;
			if (execve(command, av, NULL) == -1)
			{
				fprintf(stderr, "%s: 1: %s: not found\n ", argv[0], command);
				exit(1);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	}
	free(command);
	return (0);
}
