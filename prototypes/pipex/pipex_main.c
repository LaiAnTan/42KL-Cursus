#include "pipex.h"

/*
* call				: ./pipex infile "ls -l" "wc -l" outfile
* behaves like		: < infile ls -l | wc -l > outfile

TODO call			: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
TODO behaves like	: < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

TODO call			: ./pipex here_doc LIMITER cmd cmd1 file
TODO behaves like	: cmd << LIMITER | cmd1 >> file

! restructure time ! setup everything (files/pipes) -> fork -> run cmd

*/

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	int		pipefd[2];
	pid_t	pid[2];

	if (argc != 5)
		return (0);
	if (pipe(pipefd) == -1)
		perror("Pipe creation failed");
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
	if (pid < 0)
		perror("Fork failed");
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
	char	mode;

	if (!ft_strcmp(argv[1], "here_doc"))
		mode = 'a';
	else
		mode = 'w';
	pid = fork();
	if (pid < 0)
		perror("Fork failed");
	if (pid == 0)
	{
		redirect_outfile(argv[argc - 1], mode);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		close(pipefd[1]);
		run_cmd(argv[argc - 2], envp);
	}
	return (pid);
}