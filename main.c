#include "shell.h"

void display_prompt(void);
void executeing_inputed_command(const char *command);
int toread_inputed_command(char *input_command, size_t command_size);
int arguments(int argc, char *argv[]);
int tokenisation(void);
int parent_pid(void);
int child_pid(void);

/**
 * main - The main function
 *
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: return 0
 */
int main(int argc, char *argv[])
{
	char command_from_user[120];
	int result;

	while (1)
	{
		/* Display the shell prompt */
		display_prompt();

		/* Read the command entered by the user */
		result = toread_inputed_command(
				command_from_user,
				sizeof(command_from_user)
				);
		if (result == EOF)
		{
			/* Handle EOF (ctrl + D)*/
			rwanda_printef("\n");
			exit(EXIT_SUCCESS);
		}

		/* Execute command inputed by the user */
		executing_inputed_command(command_from_user);

		/* Call the arguments function with command line arguments */
		arguments(argc, argv);

		 /* Call the tokenisation function */
		tokenisation();

		/* process id for parent */
		parent_pid();

		/* process id for child*/
		child_pid();
	}
	return (0);
}

/**
 * display_prompt - Function to display the shell prompt
 */
void display_prompt(void)
{
	rwanda_printef("rwanda_shell\n$ ");
}

/**
 * executing_inputed_command - Function to execute the inputted command
 *
 * @command: The command to be executed
 */

/* Function that executes command entered by the user */
void executing_inputed_command(const char *command)
{
	pid_t child_process_id = fork();

	if (child_process_id == -1)
	{
		/* Print an error message if fork process fail */
		rwanda_printef("Error.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_process_id == 0)
	{
		/* Perse and execute command */
		char *args[120];
		int arg_count = 0;

		char *token = strtok((char *)command, " ");

		while (token != NULL)
		{
			args[arg_count++] = token;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		/* Execute the command */
		execvp(args[0], args);

		/* Execution fails */
		rwanda_printef("Error.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process: wait for the child process to complete */
		wait(NULL);
	}
}

/**
 * toread_inputed_command - Function to read the inputted command from the user
 *
 * @input_command: Buffer to store the input command
 * @command_size: Size of the buffer
 *
 * Return: 0 on success, EOF on end of file
 */

int toread_inputed_command(char *input_command, size_t command_size)
{
	if (fgets(input_command, command_size, stdin) == NULL)
	{
		return (EOF); /* End of file */
	}

	/* Remove the newline character from the end of the input */
	input_command[strcspn(input_command, "\n")] = '\0';
	return (0);
}
