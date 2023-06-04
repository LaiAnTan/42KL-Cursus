#include "../headers/minishell.h"

int	find_next_cmd(char **tokens, int *index_pair)
{
	int	i;

	if (!tokens)
		return (0);
	if (ft_strcmp(tokens[index_pair[1]], "|") == 0)
		++index_pair[1];

	index_pair[0] = index_pair[1];
	i = index_pair[1];

	while (tokens[i] != NULL)
	{
		if (ft_strcmp(tokens[i], "|") == 0)
		{
			index_pair[1] = i;
			break;
		}
		i++;
	}
	index_pair[1] = i;
	return (0);
}

char	**extract_cmd(char **tokens, int *index_pair)
{
	int		i;
	int		j;
	char	**cmd;
	
	find_next_cmd(tokens, index_pair);
	i = 0;
	j = index_pair[0];
	cmd = (char **) malloc (sizeof(char *) * (index_pair[1] - index_pair[0] + 1));
	while (j < index_pair[1])
	{
		cmd[i] = ft_strdup(tokens[j]);
		++i;
		++j;
	}
	cmd[i] = NULL;
	return (cmd);
}

int	parser(t_data *data)
{
	int		index_pair[2];
	char	**cmd;
	t_list	*lst;
	t_list	*node;

	index_pair[1] = 0;
	cmd = extract_cmd(data->tokens, index_pair);
	lst = ft_lstnew_cmd(cmd);
	while (data->tokens[index_pair[1]])
	{
		cmd = extract_cmd(data->tokens, index_pair);
		node = ft_lstnew_cmd(cmd);
		ft_lstadd_back(&lst, node);
	}
	// i love data leaks
	free_2d_array(&data->tokens);
	data->cmds = lst;
	return (1);
}