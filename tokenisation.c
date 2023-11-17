#include "shell.h"

/**
 * tokenisation - tokenise input
 * @str - given input
 * @strc - pointer to allocate memory for string
 * @delim - to be considered during tokenisation
 * Return: return 0
 */
int tokenisation(void)
{
	char str[] = "This is the separated word by space";
	char *strc = malloc(sizeof(char *) * strlen(str));
	char delim[] = " ";

	char *trunks;
	int i;

	strcpy(strc, str);
	trunks = strtok(strc, delim);

	while (trunks != NULL)
	{
		rwanda_printef("Trunks: %s\n", trunks);
		trunks = strtok(NULL, delim);
	}

	for (i = 0; i < 35; i++)
	{
		if (strc[i] == '\0')
		{
			rwanda_printef("\\0");
		}
		else
		{
			rwanda_printef("%c", strc[i]);
		}
	}
	return (0);
}

