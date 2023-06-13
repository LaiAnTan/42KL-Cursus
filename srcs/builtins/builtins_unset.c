/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_unset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:32:03 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/13 11:48:07 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	builtin_unset(char **args, t_data *data)
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
			continue ;
		}
		node = find_var(lst, args[i]);
		if (node != NULL)
			ft_lstdel_env(&data->vars, node);
		i++;
	}
	return (0);
}
