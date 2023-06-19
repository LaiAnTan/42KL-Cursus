/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_expansion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:31:06 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/16 11:32:07 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	break_down(char *line, int *indexes, char **temp_strings)
{
	indexes[2] = get_keyword(line, indexes[1]);
	if (indexes[1] != indexes[0])
		temp_strings[0] = ft_substr(line, indexes[0], indexes[1] - 1);
	else
		temp_strings[0] = NULL;
	temp_strings[1] = ft_substr(line, indexes[1] + 1, indexes[2]);
	temp_strings[2] = ft_substr(line, indexes[2] + 1, ft_strlen(line));
	return (indexes[2] == indexes[1]);
}

void	recombine_and_reset(char **store, char **temp_strings, int *indexes)
{
	int		i;
	char	*ret;

	if ((*store))
		free((*store));
	ret = NULL;
	ret = ft_append(ret, temp_strings[0]);
	ret = ft_append(ret, temp_strings[3]);
	ret = ft_append(ret, temp_strings[2]);
	(*store) = ret;
	indexes[1] = ft_strlen(temp_strings[0]) + ft_strlen(temp_strings[3]) - 1;
	i = -1;
	while (temp_strings[++i])
		free(temp_strings[i]);
}

char	*handle_special_case(char *line, int i, int special_case)
{
	int	left;
	int	right;

	left = (line[i - 1] != '\'' && line[i - 1] != '\"');
	if (!special_case)
		right = (line[i + 1] == '\'' || line[i + 1] == '\"');
	else
		right = (!is_token(line[i + 1]) && line[i + 1] != ' ');
	if (left && right)
		return (ft_strdup(""));
	else
		return (ft_strdup("$"));
}

void	rd_init_variables(int *special_case,
	char **string_storage, int *indexes)
{
	(*special_case) = 0;
	indexes[0] = 0;
	indexes[1] = 0;
	indexes[2] = 0;
	string_storage[4] = NULL;
}

// i have sinned
void	replace_dollar(t_data *data)
{
	int		special_case;
	int		indx[3];
	char	*ret;
	char	*strings[5];

	rd_init_variables(&special_case, strings, indx);
	ret = ft_strdup(data->line);
	while (search_symbol(&ret[indx[1]], '$') != -1)
	{
		if (ret[indx[1]] == '\"')
			special_case = !special_case;
		else if (ret[indx[1]] == '\'' && !special_case)
			indx[1] = bunny_ears(ret, indx[1], '\'');
		else if (ret[indx[1]] == '$')
		{
			if (break_down(ret, indx, strings))
				strings[3] = handle_special_case(ret, indx[2], special_case);
			else
				strings[3] = access_var(data, strings[1]);
			recombine_and_reset(&ret, strings, indx);
		}
		++indx[1];
	}
	free(data->line);
	data->line = ret;
}
