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