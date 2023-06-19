/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:31:52 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/19 13:49:13 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	builtin_exit(t_data *data, char **args)
{
	int		exit_code;

	if (count_2d_array(args) > 2)
		return (error_msg("exit", NULL, "too many arguments", 1));
	else if (args[1] == NULL)
		exit_code = 0;
	else if (!is_numeric(args[1]))
		exit_code = error_msg("exit", args[1], "numeric argument required", 2);
	else
		exit_code = ft_atoi(args[1]);
	while (exit_code >= 256)
		exit_code = exit_code - 256;
	printf("exit\n");
	return (reset_and_exit(&data->attr->def_attributes, exit_code));
}
