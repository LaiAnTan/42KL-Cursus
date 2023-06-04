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

/*
this will trim off the bunny ears in all of the tokens
*/
int	remove_ears(char **string)
{
	int	ret_val;
	int	i;

	ret_val = (*string)[0] == '\"' || (*string)[0] == '\'';
	i = 0;
	if ((*string)[0] == '\"')
		(*string) = ft_trimstr((*string), '\"');
	else if ((*string)[0] == '\'')
		(*string) = ft_trimstr((*string), '\'');
	++i;
	return (ret_val);
}

/*
this function extracts the command based on the index pair

it will first append all the tokens found into a buffer
then when it meets a space token --> ""

im too lazy to write documentation already
*/
char	**extract_cmd(char **tokens, int *index_pair)
{
	int		j;
	int		filled;
	char	**cmd;
	char	*str;

	find_next_cmd(tokens, index_pair);
	j = index_pair[0];
	str = NULL;
	cmd = malloc (sizeof(char *));
	cmd[0] = NULL;
	filled = 0;
	while (j < index_pair[1])
	{
		if (ft_strlen(tokens[j]) == 0 && filled)
		{
			cmd = realloc_append(cmd, str);
			free(str);
			str = NULL;
			filled = 0;
		}
		else
		{
			if (remove_ears(&tokens[j]) == 0)
				tokens[j] = ft_trimstr(tokens[j], ' ');
			str = ft_append(str, tokens[j]);
			filled = 1;
		}
		++j;
	}
	if (str)
	{
		cmd = realloc_append(cmd, str);
		free(str);
	}
	return (cmd);
}

/*
this function will do two things

1. seperate the token list according to the pipe token | 
2. remove the space token --> ""

it will then reconstruct a "command list" and return the list
which is the final command that would be ran
*/
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
	free_2d_array(&data->tokens);
	data->cmds = lst;
	return (1);
}