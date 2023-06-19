/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_paths_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:47:42 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/16 10:47:47 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	is_executable(char *str)
{
	if (ft_strlen(str) > 2 && str[0] == '.' && str[1] == '/')
		return (1);
	return (0);
}

int	is_absolute(char *str)
{
	if (ft_strlen(str) > 2 && str[0] == '/')
		return (1);
	return (0);
}
