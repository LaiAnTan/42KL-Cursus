/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:30:51 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/13 11:07:46 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	is_token(char c)
{
	int		i;
	char	*token;

	i = 0;
	token = (char *) malloc(sizeof(char) * 6);
	token[0] = '\'';
	token[1] = '\"';
	token[2] = '|';
	token[3] = '>';
	token[4] = '<';
	token[5] = '\0';
	while (token[i] != '\0')
	{
		if (token[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

int	bunny_ears(char *line, int stop, int to_match)
{
	++stop;
	while (line[stop] && line[stop] != to_match)
		++stop;
	return (stop);
}

int	find_token_pos(char *line, int *index_pair)
{
	int		i;
	int		tk_type;

	if (index_pair[1] + 1 >= ft_strlen(line))
		return (-1);
	i = index_pair[1] + 1;
	while (line[i] != '\0' && line[i] == ' ')
		i++;
	index_pair[0] = i;
	tk_type = is_token(line[i]);
	if (tk_type != 0)
	{
		if (line[i + 1] != '\0' && (tk_type == 4 || tk_type == 5))
		{
			if (tk_type == is_token(line[i + 1]))
				i++;
		}
		else if (tk_type == 1 || tk_type == 2)
			i = bunny_ears(line, i, line[i]);
	}
	else
	{
		while (line[i] != '\0' && !is_token(line[i]) && line[i] != ' ')
			i++;
		--i;
	}
	index_pair[1] = i;
	return (tk_type);
}

int	lexer(t_data *data)
{
	int		len;
	int		token_pos[2];
	int		ret_val;
	char	*new_token;

	len = ft_strlen(data->line);
	data->tokens = (char **) malloc (sizeof(char *));
	if (!data->tokens)
		return (0);
	token_pos[1] = -1;
	data->tokens[0] = NULL;
	while (1)
	{
		ret_val = find_token_pos(data->line, token_pos);
		if (ret_val == -1 || token_pos[1] >= len)
			break ;
		if ((ret_val == 4 || ret_val == 5)
			&& data->line[token_pos[0] - 1] != ' ')
			data->tokens = realloc_append(data->tokens, "");
		new_token = ft_substr(data->line, token_pos[0], token_pos[1]);
		data->tokens = realloc_append(data->tokens, new_token);
		if (ret_val > 0)
		{
			if (ret_val == 1 || ret_val == 2)
			{
				if (data->line[token_pos[1] + 1] == ' ')
				{
					data->tokens = realloc_append(data->tokens, "");
					++token_pos[1];
				}
			}
			else if (ret_val == 4 || ret_val == 5)
				data->tokens = realloc_append(data->tokens, "");
		}
		else if (data->line[token_pos[1] + 1] == ' ')
			data->tokens = realloc_append(data->tokens, "");
		free(new_token);
	}
	return (1);
}
