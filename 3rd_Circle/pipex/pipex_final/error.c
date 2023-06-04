/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:12:51 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/12 11:44:47 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error(char *topic, char *msg, int tbool)
{
	if (topic)
	{
		write(STDERR_FILENO, topic, ft_strlen(topic));
		write(STDERR_FILENO, ": ", 2);
		if (tbool)
			free(topic);
	}
	else
		write(STDERR_FILENO, "pipex: ", 7);
	if (msg)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	else
		write(STDERR_FILENO, strerror(errno), ft_strlen(strerror(errno)));
	write(STDERR_FILENO, "\n", 1);
	exit(0);
}
