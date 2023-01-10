/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:13:03 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/10 15:21:55 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	redirect_infile(char *infile_name)
{
	int		infilefd;

	infilefd = open(infile_name, O_RDONLY, 0777);
	if (infilefd == -1)
		error(infile_name, NULL, 0);
	dup2(infilefd, STDIN_FILENO);
	close(infilefd);
	return (infilefd);
}

int	redirect_outfile(char *outfile_name)
{
	int		outfilefd;

	outfilefd = open(outfile_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfilefd == -1)
		error(outfile_name, NULL, 0);
	dup2(outfilefd, STDOUT_FILENO);
	close(outfilefd);
	return (outfilefd);
}
