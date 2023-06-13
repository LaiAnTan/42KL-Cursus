/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:30:58 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/13 11:57:07 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			break ;
		}
		i++;
	}
	index_pair[1] = i;
	return (0);
}

int	remove_ears(char **string)
{
	int	ret_val;
	int	i;

	ret_val = ((*string)[0] == '\"' || (*string)[0] == '\'');
	i = 0;
	if ((*string)[0] == '\"')
		(*string) = ft_trimstr((*string), '\"');
	else if ((*string)[0] == '\'')
		(*string) = ft_trimstr((*string), '\'');
	++i;
	return (ret_val);
}

char	**extract_cmd(char **tokens, int *index_pair)
{
	int		j;
	char	**cmd;
	char	*str;

	find_next_cmd(tokens, index_pair);
	j = index_pair[0];
	str = NULL;
	cmd = malloc (sizeof(char *));
	cmd[0] = NULL;
	while (j < index_pair[1])
	{
		if (ft_strlen(tokens[j]) == 0)
		{
			cmd = realloc_append(cmd, str);
			free(str);
			str = NULL;
		}
		else
		{
			if (remove_ears(&tokens[j]) == 0)
				tokens[j] = ft_trimstr(tokens[j], ' ');
			str = ft_append(str, tokens[j]);
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
