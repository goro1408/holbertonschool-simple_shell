#include "shell.h"

/**
 * check_exit - Checks if the command is "exit" and terminates the program
 *              if it is.
 * @command: The command to check.
 * 
 * Return: 1 if command is "exit", 0 if the command is exit.
 */
int check_exit(char *command)
{
    if (strcmp(command, "exit") == 0)
    {
        free(command);
        exit(0);
        return 1;
    }
    return 0;
}
