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
	char *command = NULL, *av[2], *token;
	int status, i = 0;
	size_t n = 0;
	ssize_t nread;
	pid_t pid;
	(void)ac;

	while (1)
	{

		if (isatty(STDIN_FILENO))
		{
			prompt();
		}

		nread = getline(&command, &n, stdin);
		command[_strcspn(command, "\n")] = '\0';

		if (nread == -1)
		{
			perror("Exiting shell");
			free(command);
			exit(0);
		}
		
		if (strcmp(command, "exit") == 0)
		{
			free(command);
			exit(0);
		}

		if (command[0] == '\0')
		{
			continue;
		}

		token = strtok(command, " \n");
		av[0] = malloc(sizeof(char *) * 1024);
		while (token != NULL)
		{
			av[i++] = token;
			token = strtok(NULL, " \n");
		}
		av[i] = NULL;

		pid = fork();
		if (pid < 0)
		{
			fprintf(stderr, "%s\n", argv[0]);
		}
		else if (pid == 0)
		{
			if (execve(av[0], av, NULL) == -1)
			{
				fprintf(stderr, "%s: 1: %s: not found\n ", argv[0], av[0]);
				exit(1);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(command);
	return (0);
}
