#include "../../headers/minishell.h"

/*
function for the exit command in bash
handles more than 2 arguments
handles no arguments exiting with code 0
handles non numeric arguments
handles arguments with values larger than 255 (max exit code)
*/
int builtin_exit(char **args)
{
	int		exit_code;

	if (count_2d_array(args) > 2)
	{
		printf("exit: too many arguements\n");
		return (1);
	}
	else if (args[1] == NULL)
		exit_code = 0;
	else if (!is_numeric(args[1]))
	{
		printf("exit: %s: numeric arguement required", args[1]);
		exit_code = 2;
	}
	else
		exit_code = ft_atoi(args[1]);
	while (exit_code >= 256)
		exit_code = exit_code - 256;
	printf("process exited with code %d\n", exit_code);
	exit(exit_code);
	return (exit_code);
}