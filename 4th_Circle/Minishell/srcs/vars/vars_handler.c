#include "../../headers/minishell.h"

/*
this function handles the special index searching for variables ($)

the start index would be the dollar sign, the last index would be at the first character 
that isnt part of token or a space
*/
int	get_keyword(char *line, int stop)
{
	++stop;
	while (line[stop] && line[stop] != ' ' && !is_token(line[stop]) && line[stop] != '$')
		++stop;
	return (--stop);
}

/*
function that searches a symbol stated in to_find in a string line

this function is very self-explanatory

returns the index if the symbol is found, else return -1
*/
int		search_symbol(char *line, int to_find)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == to_find)
			return (i);
		++i;
	}
	return (-1);
}

/*
this function.. is needed because norminette is a bitch

resets the temporary storage used in recombine_parts, freeing all the strings inside it
*/
void	reset(char **temp_strings, int *indexes)
{
	int	i;

	indexes[1] = ft_strlen(temp_strings[0]) + ft_strlen(temp_strings[3]) - 1;
	printf("%d, %d\n", ft_strlen(temp_strings[0]), ft_strlen(temp_strings[3]));
	i = -1;
	while (temp_strings[++i])
		free(temp_strings[i]);
}

/*
this function... is also needed because norminette is also a bitch

breaks down the line based on the indexes given
the value is stored inside the temporary storage in temp_strings

example = ls $SHLVL la
temp_string[0] = 'ls '
temp_string[1] = 'SHLVL'
temp_string[2] = ' la'
*/
void	break_down(char *line, int *indexes, char **temp_strings)
{
	if (indexes[1] != indexes[0])
		temp_strings[0] = ft_substr(line, indexes[0], indexes[1] - 1);
	else
		temp_strings[0] = NULL;
	temp_strings[1] = ft_substr(line, indexes[1] + 1, indexes[2]);
	temp_strings[2] = ft_substr(line, indexes[2] + 1, ft_strlen(line));
}

/*
ah yes, another function needed because norminette, is a bitch

this function recombines all the strings found in temp_strings into a
single string using ft_append()

the recombined strings is stored in store
*/
void	recombine_parts(char **store, char **temp_strings)
{
	char	*ret;

	if ((*store))
		free((*store));
	ret = NULL;
	ret = ft_append(ret, temp_strings[0]);
	ret = ft_append(ret, temp_strings[3]);
	ret = ft_append(ret, temp_strings[2]);
	(*store) = ret;
}

// handles the $ disappearing when $"stuff"
int	one_side(char *line, int i, int in_ears)
{
	int	left;
	int	right;

	left = line[i - 1] != '\'' && line[i - 1] != '\"';
	if (!in_ears)
		right = line[i + 1] == '\'' || line[i + 1] == '\"';
	else
		right = !is_token(line[i + 1]) && line[i + 1] != ' ';
	return (left && right);
}

// i think of a better way tmr morning
void	replace_dollar(t_data *data)
{
	int		special_case;
	char	*ret;
	char	*string_storage[5];
	int		indexes[3];

	special_case = 0;
	ret = ft_strdup(data->line);
	indexes[0] = 0;
	indexes[1] = 0;
	string_storage[4] = NULL;
	while (search_symbol(&ret[indexes[1]], '$') != -1)
	{
		// printf("%s\n", &ret[indexes[1]]);
		if (ret[indexes[1]] == '\"')
			special_case = !special_case;
		else if (ret[indexes[1]] == '\'' && !special_case)
		{
			++indexes[1];
			while (ret[indexes[1]] && ret[indexes[1]] != '\'')
				++indexes[1];
		}
		else if (ret[indexes[1]] == '$')
		{
			indexes[2] = get_keyword(ret, indexes[1]);
			break_down(ret, indexes, string_storage);
			if (indexes[2] == indexes[1])
			{
				if (one_side(ret, indexes[2], special_case))
					string_storage[3] = ft_strdup("");
				else
					string_storage[3] = ft_strdup("$");
			}
			else
				string_storage[3] = access_var(data, string_storage[1]);
			recombine_parts(&ret, string_storage);
			reset(string_storage, indexes);
		}
		++indexes[1];
		// printf("index = %d\n", indexes[1]);
	}
	// printf("done replace --> %s\n", ret);
	free(data->line);
	data->line = ret;
}