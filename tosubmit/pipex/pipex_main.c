/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:13:34 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/12 11:50:40 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid[2];

	if (argc != 5)
		return (0);
	if (pipe(pipefd) == -1)
		error(NULL, "pipe failed", 0);
	pid[0] = infile_cp(argv, envp, pipefd);
	pid[1] = outfile_cp(argc, argv, envp, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], NULL, 0);
	return (0);
}

pid_t	infile_cp(char **argv, char **envp, int *pipefd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error(NULL, "fork failed", 0);
	if (pid == 0)
	{
		redirect_infile(argv[1]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		run_cmd(argv[2], envp);
	}
	return (pid);
}

pid_t	outfile_cp(int argc, char **argv, char **envp, int *pipefd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error(NULL, "fork failed", 0);
	if (pid == 0)
	{
		redirect_outfile(argv[argc - 1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		run_cmd(argv[argc - 2], envp);
	}
	return (pid);
}
