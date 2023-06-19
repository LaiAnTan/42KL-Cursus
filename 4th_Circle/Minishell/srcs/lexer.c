/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:30:51 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/19 19:39:54 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minishell.h"

int	bunny_ears(char *line, int start, int to_match)
{
	++start;
	while (line[start] && line[start] != to_match)
		++start;
	if (line[start] == '\0')
		return (-1);
	return (start);
}

int	handle_token(char *line, int tk_type, int i)
{
	if (line[i + 1] != '\0' && (tk_type == 4 || tk_type == 5))
	{
		if (tk_type == is_token(line[i + 1]))
			i++;
	}
	else if (tk_type == 1 || tk_type == 2)
		i = bunny_ears(line, i, line[i]);
	return (i);
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
		i = handle_token(line, tk_type, i);
	else
	{
		while (line[i] != '\0' && !is_token(line[i]) && line[i] != ' ')
			i++;
		--i;
	}
	index_pair[1] = i;
	return (tk_type);
}

void	pad_blank_tokens(t_data *data, int ret_val, int *token_pos)
{
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
}

// if ((ret_val == 4 || ret_val == 5)
// 	&& data->line[token_pos[0] - 1] != ' ')
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
		if ((ret_val == 4 || ret_val == 5 || ret_val == 3))
			data->tokens = realloc_append(data->tokens, "");
		new_token = ft_substr(data->line, token_pos[0], token_pos[1]);
		data->tokens = realloc_append(data->tokens, new_token);
		pad_blank_tokens(data, ret_val, token_pos);
		free(new_token);
	}
	return (1);
}
