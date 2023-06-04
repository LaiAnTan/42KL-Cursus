#include "../headers/minishell.h"

t_list	*set_env(char **envp)
{
	int		i;
	t_list	*vars;
	t_list	*node;


	i = 1;	
	vars = ft_lstnew_env(envp[0]);
	while (envp[i] != NULL)
	{
		node = ft_lstnew_env(envp[i]);
		ft_lstadd_back(&vars, node);
		i++;
	}
	return (vars);
}

int	get_equal_pos(t_list *node)
{
	int		pos;

	pos = 0;
	while (node->env.str[pos] != '\0')
	{
		if (node->env.str[pos] == '=')
			return (pos);
		pos++;
	}
	return (-1);
}

char	*get_val(t_list *node)
{
	int		i;
	int		pos;
	char	*val;

	pos = get_equal_pos(node) + 1; // 1st char after =
	val = (char *) malloc (sizeof(char) * (ft_strlen(node->env.str) - pos + 1));
	i = 0;
	while (node->env.str[pos] != '\0')
	{
		val[i] = node->env.str[pos];
		i++;
		pos++;
	}
	val[i] = '\0';
	return (val);
}

int	compare_name(char *var, char *name)
{
	int	i;

	i = 0;
	while (name[i] != '\0')
	{
		if (name[i] != var[i])
			return (0);
		++i;
	}
	if (var[i] == '=')
		return (1);
	return (0);
}

t_list	*find_var(t_list *vars, char *to_find)
{
	t_list *node;

	node = vars;
	while (node != NULL)
	{
		if (compare_name(node->env.str, to_find) == 1)
			return (node);
		node = node->next;
	}
	return (NULL);
}