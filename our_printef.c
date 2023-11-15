#include "shell.h"

void rwanda_printef(const char *inputedmessage, ...)
{
	va_list args;
	char buffer[1024];
	
	va_start(args, inputedmessage);

	/* Use a buffer to format the message*/
	vsnprintf(buffer, sizeof(buffer), inputedmessage, args);

	va_end(args);

	/* Write the formatted message to STDOUT*/
	write(STDOUT_FILENO, buffer, strlen(buffer));
}
