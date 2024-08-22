#include "shell.h"

/**
 * _strcspn - Copy of strcspn function of the string library
 * @s: The string to search
 * @accept: The characters to avoid
 *
 * Return: The length of the initial substring.
 */

size_t _strcspn(const char *s, const char *accept)
{
	size_t i = 0;

	while (s[i] != '\0')
	{
		if (strchr(accept, s[i]) != NULL)
		{
			return (i);
		}
		i++;
	}

	return (i);
}

/**
 * parse_input - Tokenizes the input buffer into an array of arguments
 * @buf: Input buffer
 * Return: Array of arguments
 */
char **parse_input(char *buf)
{
    char *token;
    char **array;
    size_t i = 0;

    array = malloc(sizeof(char *) * 1024);
    if (array == NULL)
    {
        perror("Failed to allocate memory");
        exit(1);
    }

    token = strtok(buf, " \n");
    while (token)
    {
        array[i] = token;
        token = strtok(NULL, " \n");
        i++;
    }
    array[i] = NULL;

    return (array);
}

/**
 * execute_command - Executes a command by forking a child process
 * @args: Array of arguments
 * @path: Path to the executable
 */
void execute_command(char **args, char *path)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        fprintf(stderr, "%s\n", args[0]);
        exit(41);
    }

    else if (child_pid == 0)
    {
        if (execve(path, args, NULL) == -1)
        {
			if (isatty(STDIN_FILENO))
			{
				perror(args[0]);
				exit(97);
			}

			else
			{
				exit(EXIT_FAILURE);
			}
			
        }
    }
    else
    {
        wait(&status);
    }
}

/**
 * handle_input - Handles user input, parses it, and executes the command
 */
void handle_input(void)
{
    char *buf = NULL;
    size_t count = 0;
    ssize_t nread;
    char **args;
    char *path;

    if (isatty(STDIN_FILENO))
    {
        printf("#cisfun$ ");
    }

    nread = getline(&buf, &count, stdin);
    if (nread == -1)
    {
        free(buf);
        exit(0);
    }
	args = parse_input(buf);

	if (strcmp(args[0], "exit") == 0)
	{
		free(buf);
		exit(0);
	}

    path = get_file_path(args[0]);
    execute_command(args, path);

    free(path);
    free(buf);
    free(args);
}