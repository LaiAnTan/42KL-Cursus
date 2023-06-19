/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:37:03 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/19 16:35:39 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	is_redirect(char *arg)
{
	if (ft_strcmp(arg, ">") == 0 || ft_strcmp(arg, ">>") == 0
		|| ft_strcmp(arg, "<") == 0 || ft_strcmp(arg, "<<") == 0)
	{
		return (1);
	}
	return (0);
}

int	contains_redirect(char **args)
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

int	get_redirect_type(char *arg)
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

int	count_args_without_redirect(char **args)
{
	int		i;
	int		len;
	int		count;

	i = 0;
	len = count_2d_array(args);
	count = 0;
	while (i < len)
	{
		if (is_redirect(args[i]))
			i += 2;
		else
		{
			++i;
			++count;
		}
	}
	return (count);
}
