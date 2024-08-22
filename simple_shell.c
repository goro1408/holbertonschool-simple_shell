#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	while (1)
	{
		handle_input();
	}

	return (0);
}
