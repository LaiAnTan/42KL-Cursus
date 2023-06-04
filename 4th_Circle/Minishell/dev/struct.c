#include "../headers/minishell.h"

int init_data(t_data *data, char **envp)
{
	data->stdin_backup = dup(STDIN_FILENO);
	data->stdout_backup = dup(STDOUT_FILENO);
	data->cwd = getcwd(NULL, PATH_MAX);
	data->vars = set_env(envp);
	data->cmds = NULL;
	data->my_envp = NULL;
	data->attr = malloc(sizeof(struct termios) * 2);
	tcgetattr(STDIN_FILENO, &data->attr->def_attributes);
	tcgetattr(STDIN_FILENO, &data->attr->mod_attributes);
	rebuild_envp(data);
	return (1);
}

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