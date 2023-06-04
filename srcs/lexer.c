#include "../headers/minishell.h"

/*
this function checks if the character is part of the token group

token group is ' " | < >
if it does, return a non-zero value
*/
int	is_token(char c)
{
	int		i = 0;
	char	token[] = "\'\"|><";
	
	while (token[i] != '\0')
	{
		if (token[i] == c)
			return (i + 1);
		i++;
	}
	return (0);
}

/*
this function handles the special index searching for bunny ears

specifically, the stop index

the start index would be at the first bunny ear found, the last index would be at the
last bunny ear found

these two indexes is then extracted and ft_substr is used to create the token
*/
int	bunny_ears(char *line, int stop, int to_match)
{
	++stop;
	while (line[stop] && line[stop] != to_match)
		++stop;
	return (stop);
}

/*
this function finds the index start and end for all the token

it will first skip all leading whitespaces from start
then it checks if the character is a token
if it is, a specific way of extracting the indexes will be used
if it is not, the end would be the location of the first character that is part of a token, a space or 
the adjacent character is the NULL terminating character
*/
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
		while (line[i + 1] != '\0' && !is_token(line[i + 1]) && line[i + 1] != ' ')
			i++;
	}
	index_pair[1] = i;
	return (tk_type);
}

/*
this fucking piece of broken shit will seperate all the tokens in the line of code

each token will follow the following format

(the token)(a single space to represent if it is connected to the previous token)

so a command like : ls -la a b c
will be expressed as (i hope you can see whitespaces)
[ls ] -> [-la ] -> [a ] -> [b ] -> [c ]

a command like : echo stuff"abcdef" $SHLVL'pizza'
will be expressed as
[echo ] -> [stuff] -> ["abcdef"] -> [""] (special tokens will have "" nodes instead of spaces) -> [$SHLVL] -> ['pizza']

the expander will convert the spaces into "", and remove the spaces at the words
the parser will remove the "" nodes, and combine the tokens that should be together
*/
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
		if ((ret_val == 4 || ret_val == 5) && data->line[token_pos[0] - 1] != ' ')
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