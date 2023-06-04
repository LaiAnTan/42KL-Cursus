#include "../../headers/minishell.h"


/*
function for the unset command in bash
locates the variable specified and then deletes it from the linked list of env variables
handles "_" not being able to be unset
*/
int builtin_unset(char **args, t_data *data)
{
	int		i;
	t_list	*node;
	t_list	*lst;

	i = 1;
	lst = data->vars;
	while (args[i] != NULL)
	{
		if (ft_strcmp(args[i], "_") == 0)
		{
			i++;
			continue;
		}
		node = find_var(lst, args[i]);
		if (node != NULL)
			ft_lstdel_env(&data->vars, node);
		i++;
	}
	return (0);
}