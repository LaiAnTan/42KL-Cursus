/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:34:03 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/19 20:09:29 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	single_command(t_data *data, t_list *cmds)
{
	int		exit_status;
	char	*cmd;
	char	**cmd_paths;

	cmd = ft_strdup(cmds->cmd.cmd[0]);
	exit_status = handle_builtins(cmd, cmds->cmd.cmd, data);
	if (exit_status == -1)
	{
		cmd_paths = get_cmd_path(data, cmd);
		exit_status = exec_cmd(data, cmd_paths, cmds->cmd.cmd, cmd);
		if (cmd_paths)
			free_2d_array(&cmd_paths);
	}
	if (cmd)
		free(cmd);
	return (exit_status);
}

int	get_exit_code(t_data *data, int exit_status)
{
	if (WIFEXITED(exit_status))
		data->last_exit = WEXITSTATUS(exit_status);
	else
	{
		if (WIFSIGNALED(exit_status))
			data->last_exit = 130;
	}
	return (data->last_exit);
}

int	check_valid_pipes(t_data *data)
{
	t_list	*cur;

	cur = data->cmds;
	while (cur)
	{
		if (!cur->cmd.cmd)
		{
			data->last_exit = error_msg("minishell", NULL,
					"syntax error near unexpected token", 2);
			return (0);
		}
		cur = cur->next;
	}
	return (1);
}

void	run_cmd(t_data *data)
{
	int	exit_status;

	exit_status = 0;
	if (data->cmds->next)
	{
		if (check_valid_pipes(data))
			multiple_commands(data);
	}
	else
	{
		if (!data->cmds->cmd.cmd)
			return ;
		exit_status = handle_redirect(data->cmds->cmd.cmd,
				data->cmds, data->stdin_backup);
		if (exit_status == 1)
		{
			data->last_exit = exit_status;
			return ;
		}
		data->cmds->cmd.cmd = get_cmd_args_without_redirect
			(data->cmds->cmd.cmd);
		data->last_exit = single_command(data, data->cmds);
	}
}

int	exec_cmd(t_data *data, char **cmd_paths, char **args, char *cmd)
{
	int		i;
	int		childpid;

	i = 0;
	rebuild_envp(data);
	if (!cmd_paths)
		return (error_msg(NULL, cmd, "No such file or directory", 127));
	while (cmd_paths[i] != NULL)
	{
		if (args[0] != NULL)
			free(args[0]);
		args[0] = ft_strdup(cmd_paths[i]);
		if (!(access(args[0], X_OK)))
		{
			childpid = fork();
			if (!childpid)
				exec_child(cmd_paths[i], args, data->my_envp);
			else
				return (exec_parent(data, childpid));
		}
		i++;
	}
	return (error_msg(NULL, cmd, "No such file or directory", 127));
}
