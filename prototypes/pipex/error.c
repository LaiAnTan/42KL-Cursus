#include "pipex.h"

/*
types of errors:

cant open file
command not found
cant run command
no access to command

*/

int	error(char *topic, char *msg)
{
	if (topic)
	{
		write(STDERR_FILENO, topic, ft_strlen(topic));
		write(STDERR_FILENO, ": ", 2);
		free(topic);
	}
	else
		write(STDERR_FILENO, "pipex: ", 7);
	
	if (msg)
	{
		write(STDERR_FILENO, msg, ft_strlen(msg));
		free(msg);
	}
	else
		write(STDERR_FILENO, strerror(errno), ft_strlen(strerror(errno)));
	
	write(STDERR_FILENO, "\n", 1);
	exit(0);
}