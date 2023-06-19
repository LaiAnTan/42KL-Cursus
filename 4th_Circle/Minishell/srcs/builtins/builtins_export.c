/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_export.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:31:55 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/19 14:33:27 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static char	*get_var_name(char *str)
{
	int		i;
	int		j;
	char	*var_name;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '=')
		++i;
	var_name = (char *) malloc (sizeof(char) * (i + 1));
	while (j < i)
	{
		var_name[j] = str[j];
		j++;
	}
	var_name[j] = '\0';
	return (var_name);
}

static void	replace_variable(char *line, t_list *node)
{
	if (search_symbol(line, '=') == -1)
		return ;
	free(node->env.str);
	node->env.str = ft_strdup(line);
}

int	builtin_export(char **args, t_data *data)
{
	int		i;
	char	*var_name;
	t_list	*node;

	i = 0;
	if (args[1] == NULL)
		return (print_asc_export(data->vars));
	while (args[++i] != NULL)
	{
		if (args[i][0] == '=')
			return (error_msg("export", args[i],
					"is not a valid identifier", 1));
		var_name = get_var_name(args[i]);
		node = find_var(data->vars, var_name);
		free(var_name);
		if (node == NULL)
			ft_lstadd_back(&data->vars, ft_lstnew_env(ft_strdup(args[i])));
		else
			replace_variable(args[i], node);
	}
	return (0);
}
