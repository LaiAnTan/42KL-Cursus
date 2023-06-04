#include "../../headers/minishell.h"

/*
function to check to if a string is a redirection symbol
*/
int		is_redirect(char *arg)
{
	if (ft_strcmp(arg, ">") == 0 || ft_strcmp(arg, ">>") == 0 
		|| ft_strcmp(arg, "<") == 0 || ft_strcmp(arg, "<<") == 0)
	{
		return (1);
	}
	return (0);
}

/*
function to check if a command (array of stringsg) contains a redirection symbol
*/
int		contains_redirect(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		if (is_redirect(args[i]))
			return (1);
		i++;
	}
	return (0);
}

/*
function to get the type of redirection that is passed into it
*/
int		get_redirect_type(char *arg)
{
	if (!is_redirect(arg))
		return (0);
	if (ft_strcmp(arg, ">") == 0)
		return (1);
	if (ft_strcmp(arg, ">>") == 0)
		return (2);
	if (ft_strcmp(arg, "<") == 0)
		return (3);
	if (ft_strcmp(arg, "<<") == 0)
		return (4);
	return (-1);
}