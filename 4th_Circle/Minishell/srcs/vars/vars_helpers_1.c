#include "../../headers/minishell.h"

/*
function that gets the position of the equal in an env variable
*/
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

/*
function that gets the value of the node passed as parameter
*/
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

/*
function that checks if the variable names are the same
*/
static int	compare_name(char *var, char *name)
{
	int	i;

	i = 0;
	// printf("comparing %s with %s\n", var, name);
	while (name[i] != '\0' && var[i] != '\0')
	{
		if (name[i] != var[i])
			return (0);
		++i;
	}
	if (var[i] == '=')
		return (1);
	return (0);
}

/*
function that finds and returns the node in which the variable to_find is located at
*/
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

/*
function used to access variables
if the keyword given in name begins with a ?, it will immediately return the value of
the exit value of the last command

else, it will search for the variable in the env variable list, and then return the value
of the variable using get_val()

if the keyword cannot be found in the list, it returns ""

*/
char	*access_var(t_data *data, char *name) 
{
	t_list	*lst;

	lst = data->vars;
	if (!name)
		return (ft_strdup(""));
	if (name[0] == '?')
		return (ft_itoa(data->last_exit));
	while (lst)
	{
		if (ft_strcmp_equals(lst->env.str, name) == 0)
			return(get_val(lst));
		lst = lst->next;
	}
	return (ft_strdup(""));
}