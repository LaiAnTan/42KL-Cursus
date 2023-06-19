/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:30:54 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/19 20:11:02 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	init_data(t_data *data, char **envp)
{
	data->stdin_backup = dup(STDIN_FILENO);
	data->stdout_backup = dup(STDOUT_FILENO);
	data->cwd = getcwd(NULL, 1024);
	data->vars = set_env(envp);
	data->cmds = NULL;
	data->my_envp = NULL;
	data->attr = malloc(sizeof(struct termios) * 2);
	data->last_exit = 0;
	tcgetattr(STDIN_FILENO, &data->attr->def_attributes);
	rebuild_envp(data);
	return (1);
}

int	check_ears(t_data *data)
{
	int	i;

	i = 0;
	while (data->line[i])
	{
		if (data->line[i] == '\"' || data->line[i] == '\'')
		{
			i = bunny_ears(data->line, i, data->line[i]);
			if (i == -1)
			{
				data->last_exit = 2;
				free(data->line);
				return (error_msg("syntax error", NULL,
						"unexpected EOF while looking for matching symbol", 0));
			}
		}
		++i;
	}
	return (1);
}

int	handle_line(t_data *data)
{
	char	*line;

	line = readline("\x1b[31;1m" "Minishell$ " "\x1b[m");
	if (line)
	{
		if (line[0] == '\0')
		{
			free(line);
			return (0);
		}
		add_history(line);
		rl_redisplay();
		data->line = ft_strdup(line);
		free(line);
		return (check_ears(data));
	}
	else
		exit(reset_and_exit(&data->attr->def_attributes, 0));
}

int	valid_cmds(t_data *data)
{
	int		i;
	t_list	*curr;

	i = 0;
	curr = data->cmds;
	while (curr)
	{
		while (curr->cmd.cmd && curr->cmd.cmd[i] != NULL)
		{
			if (is_redirect(curr->cmd.cmd[i]) == 1
				&& (is_redirect(curr->cmd.cmd[i + 1]) == 1
					|| curr->cmd.cmd[i + 1] == NULL))
			{
				data->last_exit = 2;
				return (error_msg(NULL, "minishell",
						"syntax error near unexpected token", 2));
			}
			++i;
		}
		i = 0;
		curr = curr->next;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_data			data;

	(void)argv;
	if (argc != 1)
		return (0);
	init_data(&data, envp);
	tcgetattr(STDOUT_FILENO, &data.attr->mod_attributes);
	data.attr->mod_attributes.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &data.attr->mod_attributes);
	while (1)
	{
		signal(SIGINT, new_line_handler);
		signal(SIGQUIT, SIG_IGN);
		if (!handle_line(&data))
			continue ;
		replace_dollar(&data);
		lexer(&data);
		parser(&data);
		if (valid_cmds(&data) == 0)
			run_cmd(&data);
		cleanup(&data);
	}
	if (data.vars)
		ft_lstfree(&data.vars);
	return (reset_and_exit(&data.attr->def_attributes, 0));
}
