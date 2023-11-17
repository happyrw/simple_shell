#include "shell.h"

/**
 * child_pid - give the process id of child
 * rwanda_printef - work as printf
 * Return: return 0
 */
int child_pid(void)
{
	rwanda_printef("%u\n", getpid());

	return (0);
}
