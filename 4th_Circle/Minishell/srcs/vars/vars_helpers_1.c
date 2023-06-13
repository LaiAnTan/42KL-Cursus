/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_helpers_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:31:09 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/13 17:24:26 by cshi-xia         ###   ########.fr       */
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

static int	compare_name(char *var, char *name)
{
	int	i;

	i = 0;
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

t_list	*find_var(t_list *vars, char *to_find)
{
	t_list	*node;

	node = vars;
	while (node != NULL)
	{
		if (compare_name(node->env.str, to_find) == 1)
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
