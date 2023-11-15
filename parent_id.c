#include "shell.h"

int parent_pid()
{
	pid_t parent_id;

	parent_id = getppid();
	rwanda_printef("%u\n", parent_id);

	return (0);
}
