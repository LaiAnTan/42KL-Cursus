/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_mains.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:37:22 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/19 19:26:54 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/*
function to get the information of the next redirect in a command 
an int array with 2 elements is returned
redirect_info[0] = type of redirection
redirect_info[1] = index of redirection symbol
*/

int	*get_next_redirect(char **args, int index)
{
	int	*redirect_info;

	if (index >= count_2d_array(args))
		return (NULL);
	redirect_info = (int *) malloc(sizeof(int) * 2);
	while (args[index] != NULL)
	{
		redirect_info[0] = get_redirect_type(args[index]);
		if (redirect_info[0] != 0)
		{
			redirect_info[1] = index;
			return (redirect_info);
		}
		++index;
	}
	redirect_info[0] = -1;
	redirect_info[1] = -1;
	return (redirect_info);
}

/*
function that gets the raw command and its arguments without the redirection
*/
char	**get_cmd_args_without_redirect(char **args)
{
	int		i;
	int		j;
	int		old_len;
	int		new_len;
	char	**new;

	if (contains_redirect(args) == 0)
		return (args);
	i = 0;
	j = 0;
	old_len = count_2d_array(args);
	new_len = count_args_without_redirect(args);
	new = malloc (sizeof(char *) * (new_len + 1));
	while (i < old_len)
	{
		if (is_redirect(args[i]))
			i += 2;
		else
			new[j++] = ft_strdup(args[i++]);
	}
	new[new_len] = NULL;
	free_2d_array(&args);
	return (new);
}

// this will never go inside else
// ...right?
int	redirect_switcher(int *redirect_info, t_list *cur, char *args, int std_in)
{
	if (redirect_info[0] == 1)
		return (handle_redir_output(args, &cur->out_fd));
	else if (redirect_info[0] == 2)
		return (handle_redir_output_append(args, &cur->out_fd));
	else if (redirect_info[0] == 3)
		return (handle_redir_input(args, &cur->in_fd));
	else if (redirect_info[0] == 4)
		return (handle_redir_input_heredoc(args, &cur->in_fd, std_in));
	else
		return (1);
}

int	handle_redirect(char **args, t_list *cur, int std_in)
{
	int		i;
	int		*redirect_info;

	i = 0;
	if (contains_redirect(args) == 0)
		return (0);
	while (args[i] != NULL)
	{
		redirect_info = get_next_redirect(args, i);
		if (redirect_info == NULL)
			return (-1);
		else if (redirect_info[0] == -1 && redirect_info[1] == -1)
			break ;
		i = redirect_info[1] + 1;
		if (redirect_switcher(redirect_info, cur, args[i], std_in) == 1)
		{
			free(redirect_info);
			return (1);
		}
	}
	if (redirect_info)
		free(redirect_info);
	return (0);
}
