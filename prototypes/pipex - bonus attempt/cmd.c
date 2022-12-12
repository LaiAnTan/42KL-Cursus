#include "pipex.h"

void	run_next_cmd(t_pipex pipex, char **argv, int i)
{
		pipex.currcmd = argv[i];
		pipex.currcmdargs = ft_split(pipex.currcmd, ' ');
		append_cmd(pipex.paths, pipex.currcmdargs[0]);
		if (exec_cmd(pipex.paths, pipex.currcmdargs, pipex.envp))
			exit (0);
}

int	exec_cmd(char **cmd_paths, char **args, char **envp)
{
	int		i;
	int		status;

	i = 0;
	while (cmd_paths[i])
	{
		free(args[0]);
		args[0] = ft_strdup(cmd_paths[i]);
		status = access(args[0], X_OK);
		if (!status)
			execve(cmd_paths[i], args, envp);
		else
			i++;
	}
	perror("Command not found");
	return (-1);
}
