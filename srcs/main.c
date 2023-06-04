#include "../headers/minishell.h"

/*
initializes the data structure that stores all the data required by the program
converts the environment variables into a linked list and stores it
tores the current working directory
intializes 2 termios structures for later use
*/
int init_data(t_data *data, char **envp)
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
	tcgetattr(STDIN_FILENO, &data->attr->mod_attributes);
	rebuild_envp(data);
	return (1);
}

/*
function that handles reading user input and history
*/
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
		exit(0); // handle ctrl + D
}

/*
debug function for printing commands
*/
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
			printf("%d | %s | %d\n", i, iter->cmd.cmd[i], ft_strlen(iter->cmd.cmd[i]));
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

void	replace_dollar(t_data *data);

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
		signal(SIGINT, new_line_handler);
		signal(SIGQUIT, SIG_IGN);
		if (!handle_line(&data))
			continue;
		replace_dollar(&data);

		lexer(&data);
		print_double(data.tokens);

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
	if (data.vars)
		ft_lstfree(&data.vars);
	return (0);
}