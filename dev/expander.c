#include "../headers/minishell.h"

/*
note: this function can be removed along with strcmp_equals
! use get_val which returns the node and modify the code a little during cleanup

suggestion - gay sex
*/
char	*access_var(t_data *data, char *name) 
{
	t_list	*lst;

	lst = data->vars;
	while (lst)
	{
		if (ft_strcmp_equals(lst->env.str, name) == 0)
			return(get_val(lst));
		lst = lst->next;
	}
	return (ft_strdup(""));
}

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
	return -1;
}

void	reset_storage(char **temp_strings)
{
	int	i;

	i = -1;
	while (temp_strings[++i])
		free(temp_strings[i]);
}

void	break_down(char *line, int *indexes, char **temp_strings) // why do i hear josuke // i am about to have a break-down break-down
{
	// example = ls $SHLVL la
	// temp_string[0] = 'ls '
	// temp_string[1] = 'SHLVL'
	// temp_string[2] = ' la'

	temp_strings[0] = ft_substr(line, indexes[0], indexes[1] - 1);
	temp_strings[1] = ft_substr(line, indexes[1] + 1, indexes[2]);
	temp_strings[2] = ft_substr(line, indexes[2] + 1, ft_strlen(line));
}

char	*recombine_parts(char **temp_strings, int *indexes)
{
	char	*ret;

	ret = NULL;
	if (indexes[1] != indexes[0])
		ret = ft_append(ret, temp_strings[0]);
	ret = ft_append(ret, temp_strings[3]);
	ret = ft_append(ret, temp_strings[2]);
	return (ret);
}

char	*handle_dollar(t_data *data, char *line)
{
	char	*ret;
	// lord forgive me for i have sinned
	char	*temp_strings[5];
	int		indexes[3];

	ret = ft_trimstr(line, '\"');
	indexes[0] = 0;
	temp_strings[4] = NULL;
	while (1)
	{
		// get the start of the keyword
		indexes[1] = search_symbol(ret, '$');

		// no more dollar signs = no more variables
		if (indexes[1] == -1)
			return (ret);

		// get the end of the keyword
		indexes[2] = get_keyword(ret, indexes[1]);
		break_down(ret, indexes, temp_strings);

		temp_strings[3] = access_var(data, temp_strings[1]);

		free(ret);
		ret = NULL;
		ret = recombine_parts(temp_strings, indexes);

		reset_storage(temp_strings);
	}
}

int	expander(t_data *data) // forgot to handle $? lol
{
	int		i;
	char	**new;
	int		tokencount = count_2d_array(data->tokens);

	i = 0;
	new = malloc (sizeof(char *));
	new[0] = NULL;
	if (!data || !data->tokens)
		return (0);
	
	printf("expander: \n");
	while (i < tokencount)
	{
		// this will fail if tokens[i] is NULL
		// ...which it should not be
		if (data->tokens[i][0] == '\"')
		{
			new = realloc_append(new, handle_dollar(data, data->tokens[i]));
			i++;
		}
		else if (data->tokens[i][0] == '\'')
		{
			new = realloc_append(new, ft_trimstr(data->tokens[i], '\''));
			i++;
		}
		else
		{
			new = realloc_append(new, handle_dollar(data, data->tokens[i]));
			i++;
		}
	}
	free_2d_array(&data->tokens);
	data->tokens = new;
	return (1);
}
