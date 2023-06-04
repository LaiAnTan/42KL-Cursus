#include "../../headers/minishell.h"

/*
function that converts the linked list of env variables into a 2d array inside data
*/
void	rebuild_envp(t_data *data)
{
	int		i;
	int		lst_size;
	t_list	*lst;
	t_list	*head;

	i = 0;
	lst = data->vars;
	lst_size = ft_lstsize(lst);
	head = lst;
	if (data->my_envp != NULL)
		free_2d_array(&data->my_envp);
	data->my_envp = (char **) malloc(sizeof(char *) * (lst_size + 1));
	while (lst != NULL)
	{
		data->my_envp[i] = ft_strdup(lst->env.str);
		i++;
		lst = lst->next;
	}
	data->my_envp[i] = NULL;
	lst = head;
}

/*
function that converts the envp array of strings into a linked list
*/
t_list	*set_env(char **envp)
{
	int		i;
	t_list	*vars;
	t_list	*node;


	i = 0;
	vars = NULL;
	while (envp[i] != NULL)
	{
		node = ft_lstnew_env(ft_strdup(envp[i]));
		ft_lstadd_back(&vars, node);
		i++;
	}
	return (vars);
}