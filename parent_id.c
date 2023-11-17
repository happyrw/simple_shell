#include "shell.h"

/**
 * parent_pid - process the parent process id
 * @parent_id - store the value of parent process id
 * Return: return 0
 */
int parent_pid(void)
{
	pid_t parent_id;

	parent_id = getppid();
	rwanda_printef("%u\n", parent_id);

	return (0);
}
