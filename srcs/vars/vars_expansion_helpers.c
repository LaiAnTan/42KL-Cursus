/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_expansion_helpers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:43:47 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/16 10:49:05 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	get_keyword(char *line, int stop)
{
	++stop;
	while (line[stop] && line[stop] != ' '
		&& !is_token(line[stop]) && line[stop] != '$')
		++stop;
	return (--stop);
}
