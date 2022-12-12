#include "pipex.h"

int	redirect_infile(char *infile_name)
{
	int		infilefd;

	infilefd = open(infile_name, O_RDONLY, 0777); // open infile
	if (infilefd == -1)
		perror("file could not be opened");
	dup2(infilefd, STDIN_FILENO); // STDIN is now infilefd
	close(infilefd);
	return (infilefd);
}

int	redirect_outfile(char *outfile_name, char c)
{
	int		outfilefd;
	int		mode;

	if (c == 'w')
		mode = O_WRONLY;
	else if (c == 'a')
		mode = O_WRONLY | O_APPEND;
	outfilefd = open(outfile_name, mode, 0777);
	if (outfilefd == -1)
		perror("file could not be opened");
	dup2(outfilefd, STDOUT_FILENO); // STDOUT is now outfilefd
	close(outfilefd);
	return (outfilefd);
}

int		redirect_heredoc(t_pipex *pipex, char **argv, int argc, int pipe[2])
{
	pipex ->outfilefd = open(argv[argc - 1], O_WRONLY | O_APPEND, 0777);
	heredoc(pipe[1], argv[2]);
	close(pipe[1]);
	pipex ->infilefd = pipe[0];
}

void	heredoc(int outfd, char *limiter)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		printf("line: %s", line);
		if (!ft_strcmp(line, limiter))
			break ;
		write(outfd, line, ft_strlen(line));
		free(line);

	}
	free(line);
}