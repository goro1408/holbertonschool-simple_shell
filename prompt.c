#include "shell.h"

/**
 * prompt - gives you the prompt character for simple shell
 */

void prompt(void)
{
	printf("$ ");
	fflush(stdout);
}

size_t strcspn(const char s, const charreject) {
    const char p = s;
    while (p && !strchr(reject, *p)) {
        p++;
    }
    return p - s;
}
