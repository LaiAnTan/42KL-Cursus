/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_handlers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:36:25 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/19 16:27:40 by tlai-an          ###   ########.fr       */
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
		return (error_msg(NULL, filename, "No such file or directory", 1));
	dup2(fd, *in_fd);
	return (0);
}

// exit can quite literally be anything
int	heredoc_child(char *delimiter, int *storage, int std_in)
{
	char	*line;

	line = NULL;
	close(storage[0]);
	dup2(std_in, STDIN_FILENO);
	while (1)
	{
		line = readline("> ");
		rl_redisplay();
		if (!line)
		{
			error_msg("warning", delimiter,
				"here-document at line 28 delimited by end-of-file", 0);
			break ;
		}
		if (ft_strcmp(line, delimiter) == 0)
			break ;
		write(storage[1], line, ft_strlen(line));
		write(storage[1], "\n", 1);
		free(line);
	}
	if (line)
		free(line);
	exit(69);
}

// close(storage[0]);
// dup2(std_in, STDIN_FILENO);
// while (1)
// {
// 	line = readline("> ");
// 	rl_redisplay();
// 	if (ft_strcmp(line, delimiter) == 0)
// 		break ;
// 	write(storage[1], line, ft_strlen(line));
// 	write(storage[1], "\n", 1);
// 	free(line);
// }
// exit(0);

int	handle_redir_input_heredoc(char *delimiter, int *in_fd, int std_in)
{
	int		child_fd;
	int		storage[2];

	if (is_redirect(delimiter))
		return (-1);
	pipe(storage);
	child_fd = fork();
	if (!child_fd)
		heredoc_child(delimiter, storage, std_in);
	close(storage[1]);
	waitpid(child_fd, 0, 0);
	dup2(storage[0], *in_fd);
	return (0);
}

int	handle_redir_output(char *filename, int *out_fd)
{
	int	fd;

	if (is_redirect(filename))
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (error_msg(NULL, filename, "File could not be opened", 1));
	dup2(fd, *out_fd);
	close(fd);
	return (0);
}

int	handle_redir_output_append(char *filename, int *out_fd)
{
	int	fd;

	if (is_redirect(filename))
		return (-1);
	fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		return (error_msg(NULL, filename, "File could not be opened", 1));
	dup2(fd, *out_fd);
	close(fd);
	return (0);
}
