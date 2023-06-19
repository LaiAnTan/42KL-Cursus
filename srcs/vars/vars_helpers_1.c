/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_helpers_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:31:09 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/19 13:46:05 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

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

	if (get_equal_pos(node) == -1)
		return (ft_strdup(""));
	pos = get_equal_pos(node) + 1;
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

t_list	*find_var(t_list *vars, char *to_find)
{
	t_list	*node;

	node = vars;
	while (node)
	{
		if (ft_strcmp_equals(node->env.str, to_find) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

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
			return (get_val(lst));
		lst = lst->next;
	}
	return (ft_strdup(""));
}
