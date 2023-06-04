#include "../headers/minishell.h"

int	handle_line(t_data *data)
{
	char	*line;

	line = readline("\x1b[31;1m" "Minishell$ " "\x1b[m");
	if (line && *line)
	{
		add_history(line);
		rl_redisplay();
		data->line = ft_strdup(line);
		free(line);
		return (1);
	}
	else
		exit(0); // handle ctrl + D
	return (0);
}

// debug function for printing commands
void	print_parsed(t_list *amogus)
{
	t_list *iter;
	int		iter_count;

	iter_count = 1;
	iter = amogus;
	while (iter)
	{
		printf("<Cmd %d>\n", iter_count);
		for (int i = 0; iter->cmd.cmd[i]; ++i)
			printf("%d | %s\n", i, iter->cmd.cmd[i]);
		iter = iter->next;
		++iter_count;
	}
}

int main(int argc, char **argv, char **envp)
{
	(void) argv;
	t_data data;

	if (argc != 1)
		return (0);
	init_data(&data, envp);
	modify_attr(&data);
	while (1)
	{
		signal(SIGINT, new_line_handler); // ctrl + C
		signal(SIGQUIT, SIG_IGN); // ctrl + /
		if (!handle_line(&data))
			continue;
		lexer(&data);
		expander(&data);
		parser(&data);
		print_parsed(data.cmds);
		run_cmd(&data);
		dup2(data.stdin_backup, STDIN_FILENO);
		dup2(data.stdout_backup, STDOUT_FILENO);
		if (data.cmds)
			ft_lstfree(&data.cmds);
		if (data.line)
			free(data.line);

	}
	ft_lstfree(&data.vars);
	return (0);
}