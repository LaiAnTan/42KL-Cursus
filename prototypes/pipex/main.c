#include "pipex.h"

/*
call 			: ./pipex infile "ls -l" "wc -l" outfile
behaves like 	: < infile ls -l | wc -l > outfile
*/

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		pid1;
	int		pid2;

	if (argc != 5)
		return (-1);
	if (pipe(pipefd) == -1)
		perror("Pipe creation failed");
	pid1 = fork();
	if (pid1 < 0)
		perror("Fork 1 failed");
	if (pid1 == 0) //child process for command 1
	{
		redirect_infile(argv[1]);
		dup2(pipefd[1], STDOUT_FILENO); // STDOUT is now the write end of pipe
		close(pipefd[0]);
		close(pipefd[1]);
		run_cmd(argv[2], envp);
	}
	pid2 = fork();
	if (pid2 < 0)
		perror("Fork 2 failed");
	if (pid2 == 0) //child process for command 2
	{
		redirect_outfile(argv[4]);
		dup2(pipefd[0], STDIN_FILENO); // STDIN is now the read end of pipe
		close(pipefd[0]);
		close(pipefd[1]);
		run_cmd(argv[3], envp);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}