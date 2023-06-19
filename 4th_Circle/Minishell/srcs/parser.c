/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:30:58 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/19 19:36:38 by cshi-xia         ###   ########.fr       */
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

void	extract_cmd_helper(char ***cmd, char **token, char **str)
{
	if (ft_strlen((*token)) == 0)
	{
		if ((*str))
		{
			(*cmd) = realloc_append((*cmd), (*str));
			free((*str));
			(*str) = NULL;
		}
	}
	else
	{
		if (remove_ears(token) == 0)
			(*token) = ft_trimstr((*token), ' ');
		(*str) = ft_append((*str), (*token));
	}
}

char	**extract_cmd(char **tokens, int *index_pair)
{
	int		j;
	char	*str;
	char	**cmd;

	find_next_cmd(tokens, index_pair);
	if (index_pair[0] > index_pair[1])
		return (NULL);
	j = index_pair[0];
	str = NULL;
	cmd = NULL;
	while (j < index_pair[1])
	{
		extract_cmd_helper(&cmd, &tokens[j], &str);
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
