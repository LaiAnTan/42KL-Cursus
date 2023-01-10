#include "pipex.h"

int	redirect_infile(char *infile_name)
{
	int		infilefd;

	infilefd = open(infile_name, O_RDONLY, 0777); // open infile
	if (infilefd == -1)
		error(infile_name, NULL, 0);
	dup2(infilefd, STDIN_FILENO); // STDIN is now infilefd
	close(infilefd);
	return (infilefd);
}

int	redirect_outfile(char *outfile_name)
{
	int		outfilefd;

	outfilefd = open(outfile_name, O_WRONLY | O_CREAT, 0777);
	if (outfilefd == -1)
		error(outfile_name, NULL, 0);
	dup2(outfilefd, STDOUT_FILENO); // STDOUT is now outfilefd
	close(outfilefd);
	return (outfilefd);
}