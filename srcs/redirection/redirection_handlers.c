/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handlers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:36:25 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/13 17:18:11 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	handle_redir_input(char *filename, int *in_fd)
{
	int		fd;

	if (is_redirect(filename))
		return (-1);
	fd = open(filename, O_RDONLY, 0777);
	if (fd == -1)
	{
		printf("%s: No such file or directory\n", filename);
		return (-1);
	}
	dup2(fd, *in_fd);
	return (1);
}

int	handle_redir_input_heredoc(char *delimiter, int *in_fd, int std_in)
{
	int		child_fd;
	int		storage[2];
	char	*line;

	if (is_redirect(delimiter))
		return (-1);
	pipe(storage);
	line = NULL;
	child_fd = fork();
	if (!child_fd)
	{
		close(storage[0]);
		dup2(std_in, STDIN_FILENO);
		while (1)
		{
			line = readline("> ");
			rl_redisplay();
			if (ft_strcmp(line, delimiter) == 0)
				break ;
			write(storage[1], line, ft_strlen(line));
			write(storage[1], "\n", 1);
			free(line);
		}
		exit(0);
	}
	close(storage[1]);
	waitpid(child_fd, 0, 0);
	dup2(storage[0], *in_fd);
	return (1);
}

int	handle_redir_output(char *filename, int *out_fd)
{
	int	fd;

	if (is_redirect(filename))
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
	{
		printf("%s: No such file or directory\n", filename);
		return (-1);
	}
	dup2(fd, *out_fd);
	close(fd);
	return (1);
}

int	handle_redir_output_append(char *filename, int *out_fd)
{
	int	fd;

	if (is_redirect(filename))
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0777);
	if (fd == -1)
	{
		printf("%s: No such file or directory\n", filename);
		return (-1);
	}
	dup2(fd, *out_fd);
	close(fd);
	return (1);
}
