/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:12:45 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/10 14:34:25 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_cmd(char *cmd_with_params, char **envp)
{
	char	*cmd;
	char	**args;
	char	**cmd_paths;

	args = ft_split(cmd_with_params, ' ');
	cmd = ft_strdup(args[0]);
	cmd_paths = get_cmd_path(envp, cmd);
	exec_cmd(cmd, cmd_paths, args, envp);
}

void	free_2d_arrays(char **a, char **b)
{
	int		i;

	i = 0;
	while (a[i])
		free(a[i++]);
	i = 0;
	while (b[i])
		free(b[i++]);
	free(a);
	free(b);
}

int	exec_cmd(char *cmd, char **cmd_paths, char **args, char **envp)
{
	int		i;
	int		status;

	i = 0;
	while (cmd_paths[i])
	{
		if (args[0])
			free(args[0]);
		args[0] = ft_strdup(cmd_paths[i]);
		status = access(args[0], X_OK);
		if (!status)
		{
			if (execve(cmd_paths[i], args, envp) == -1)
			{
				free_2d_arrays(cmd_paths, args);
				error(cmd, "command execution failed", 1);
			}
		}
		else
			i++;
	}
	free_2d_arrays(cmd_paths, args);
	error(cmd, "command not found", 1);
	return (-1);
}
