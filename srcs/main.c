/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:30:54 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/13 17:34:27 by cshi-xia         ###   ########.fr       */
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
		return (1);
	}
	else
		exit(reset_and_exit(&data->attr->def_attributes, 0));
}

void	print_parsed(t_list *amogus)
{
	int		iter_count;
	t_list	*iter;

	iter_count = 1;
	iter = amogus;
	while (iter)
	{
		printf("<Cmd %d>\n", iter_count);
		for (int i = 0; iter->cmd.cmd[i]; ++i)
			printf("%d | %s | %d\n", i,
				iter->cmd.cmd[i], ft_strlen(iter->cmd.cmd[i]));
		iter = iter->next;
		++iter_count;
	}
}

void	print_double(char **stuff)
{
	for (int i = 0; stuff[i]; ++i)
	{
		printf("%s - len = %d\n", stuff[i], ft_strlen(stuff[i]));
	}
}

void	cleanup(t_data *data)
{
	dup2(data->stdin_backup, STDIN_FILENO);
	dup2(data->stdout_backup, STDOUT_FILENO);
	if (data->cmds)
		ft_lstfree(&data->cmds);
	if (data->line)
		free(data->line);
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
		if (data.cmds)
			run_cmd(&data);
		cleanup(&data);
	}
	if (data.vars)
		ft_lstfree(&data.vars);
	return (reset_and_exit(&data.attr->def_attributes, 0));
}
