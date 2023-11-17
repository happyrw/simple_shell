#include "shell.h"

/**
 * arguments - receive arugument from user
 * rwanda_printef - work as printf
 * @argc: argumets count
 * @argv: arguments vector
 * Return: return 0
 */
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
