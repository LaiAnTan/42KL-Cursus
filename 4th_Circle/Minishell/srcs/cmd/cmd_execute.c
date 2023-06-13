/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:34:03 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/13 11:58:50 by tlai-an          ###   ########.fr       */
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
		free_2d_array(&cmd_paths);
	}
	if (cmd)
		free(cmd);
	return (exit_status);
}

int	get_command_count(t_data *data)
{
	t_list	*counter;
	int		ret;

	ret = 0;
	counter = data->cmds;
	while (counter)
	{
		++ret;
		counter = counter->next;
	}
	return (ret);
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

void	multiple_commands(t_data *data)
{
	t_list	*curr;
	int		dispatched;
	int		cmd_count;
	int		pipe_storage[2];
	int		prev_pipe;
	int		status;
	int		last_child_pid;

	dispatched = 0;
	cmd_count = get_command_count(data);
	curr = data->cmds;
	while (dispatched < cmd_count)
	{
		if (!dispatched)
		{
			pipe(pipe_storage);
			curr->out_fd = pipe_storage[1];
		}
		else if (dispatched == cmd_count - 1)
			curr->in_fd = prev_pipe;
		else
		{
			curr->in_fd = prev_pipe;
			pipe(pipe_storage);
			curr->out_fd = pipe_storage[1];
		}
		last_child_pid = fork();
		if (last_child_pid == 0)
		{
			signal(SIGINT, SIG_DFL);
			signal(SIGQUIT, SIG_DFL);
			if (!(dispatched == cmd_count - 1))
				close(pipe_storage[0]);
			if (handle_redirect(curr->cmd.cmd, &curr->in_fd,
					&curr->out_fd, data->stdin_backup) == -1)
				exit (1);
			curr->cmd.cmd = get_cmd_args_without_redirect(curr->cmd.cmd);
			dup2(curr->in_fd, STDIN_FILENO);
			dup2(curr->out_fd, STDOUT_FILENO);
			exit (single_command(data, curr));
		}
		else
		{
			if (!dispatched)
			{
				close(pipe_storage[1]);
				prev_pipe = pipe_storage[0];
			}
			else if (dispatched == cmd_count - 1)
				close(prev_pipe);
			else
			{
				close(prev_pipe);
				close(pipe_storage[1]);
				prev_pipe = pipe_storage[0];
			}
			++dispatched;
			curr = curr->next;
		}
	}
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	while (cmd_count)
	{
		waitpid(last_child_pid, &status, 0);
		if (last_child_pid)
			get_exit_code(data, status);
		last_child_pid = 0;
		--cmd_count;
	}
}

void	run_cmd(t_data *data)
{
	if (data->cmds->next)
		multiple_commands(data);
	else
	{
		if (handle_redirect(data->cmds->cmd.cmd, &data->cmds->in_fd,
				&data->cmds->out_fd, data->stdin_backup) == -1)
		{
			data->last_exit = 1;
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
	int		status;

	i = 0;
	rebuild_envp(data);
	if (!cmd_paths)
	{
		printf("%s: No such file or directotry\n", cmd);
		return (127);
	}
	while (cmd_paths[i] != NULL)
	{
		if (args[0] != NULL)
			free(args[0]);
		args[0] = ft_strdup(cmd_paths[i]);
		status = access(args[0], X_OK);
		if (!status)
		{
			if (!fork())
			{
				signal(SIGINT, SIG_DFL);
				signal(SIGQUIT, SIG_DFL);
				if (execve(cmd_paths[i], args, data->my_envp) == -1)
				{
					free_2d_array(&cmd_paths);
					free_2d_array(&args);
					exit(errno);
				}
			}
			else
			{
				signal(SIGINT, SIG_IGN);
				signal(SIGQUIT, SIG_IGN);
				waitpid(-1, &status, 0);
				return (get_exit_code(data, status));
			}
		}
		i++;
	}
	printf("%s: command not found\n", cmd);
	return (127);
}
