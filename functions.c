#include "shell.h"

/**
 * prompt - gives you the prompt character for simple shell
 */

void prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

size_t _strcspn(const char *s, const char *accept)
{
	size_t i = 0;
	
	while (s[i] != '\0')
	{
		if (strchr(accept, s[i]) != NULL)
		{
			return i;
		}
		i++;
	}

	return i;
}
