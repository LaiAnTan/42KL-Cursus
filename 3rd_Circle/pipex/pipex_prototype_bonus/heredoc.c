#include "pipex.h"

int		heredoc(t_pipex *pipex, char **argv, int argc, int pipe[2])
{
	char	*line;

	pipex ->infilefd = pipe[0];
	pipex ->outfilefd = open(argv[argc - 1], O_WRONLY | O_APPEND, 0777);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!ft_strcmp(line, argv[2]))
			break ;
		write(pipe[1], line, ft_strlen(line));
		free(line);

	}
	free(line);
	close(pipe[1]);
}