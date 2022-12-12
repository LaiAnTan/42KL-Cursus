#include "pipex.h"

/*
* call				: ./pipex infile "ls -l" "wc -l" outfile
* behaves like		: < infile ls -l | wc -l > outfile

TODO call			: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
TODO behaves like	: < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2

TODO call			: ./pipex here_doc LIMITER cmd cmd1 file
TODO behaves like	: cmd << LIMITER | cmd1 >> file

! restructure time ! setup everything (files/paths) -> fork -> run cmd

*/

int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	int		hd_pipe[2];
	int		i;

	if (argc < 5)
		return (0);
	pipex.envp = envp;
	pipex.fullpathstr = get_path_envp(envp);
	pipex.paths = get_cmd_path(envp);
	pipex.cmdnum = argc - 3;
	if (!ft_strcmp(argv[1], "here_doc"))
	{
		if (pipe(hd_pipe) == -1)
			perror("pipe failed");
		redirect_heredoc(&pipex, argv, argc, hd_pipe);
		i = 3;
		pipex.cmdnum--;
	}
	else
	{
		i = 2;
		pipex.infilefd = open(argv[1], O_RDONLY, 0777);
		pipex.outfilefd = open(argv[argc - 1], O_WRONLY, 0777);
	}
	pipex.currcmd = argv[i];

	int		first_cp;
	first_cp = fork();
	if (first_cp == 0);
		manage_child(pipex, argv, pipex.outfilefd, 0);
	waitpid(first_cp, NULL, 0);
	return (0);
}

void	manage_child(t_pipex pipex, char **argv, int out, int index)
{
	int		new_pipe[2];
	int		new_pid;

	index++;
	dup2(out, STDOUT_FILENO);
	close(out);
	if (index < pipex.cmdnum)
	{
		if (pipe(new_pipe) == -1)
			perror("pipe failed");
		dup2(new_pipe[0], STDIN_FILENO);
		close(new_pipe[0]);
		new_pid = fork();
		if (new_pid == 0)
			manage_child(pipex, argv, new_pipe[1], index);
		else
			close(new_pipe[1]);
	}
	else
	{
		dup2(pipex.infilefd, STDIN_FILENO);
		close(pipex.infilefd);
	}
	run_next_cmd(pipex, argv, pipex.cmdnum - index);
}
