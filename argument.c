#include "shell.h"

int arguments(int argc, char *argv[])
{
	rwanda_printef("Argc = %d\n", argc);
	rwanda_printef("Argv: argv[]\n");

	while (*argv != NULL)
	{
		rwanda_printef("argv = %s\n", *argv);
		argv++;
	}
	return (0);
}
