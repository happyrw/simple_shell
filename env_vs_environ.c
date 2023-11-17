#include "shell.h"

/**
 * environment - print environment
 * @ac: argument count
 * @av: argument vector
 * @env: pointer for input
 * Return: return 0
 */
int environment(int ac, char *av[], char **env)
{

	rwanda_printef("%p\n %p\n", (void *av), (void *)env);
	return (0);
}
