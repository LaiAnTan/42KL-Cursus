#include "pipex.h"

void	run_cmd(char *cmd_with_params, char **envp)
{
	char	*cmd;
	char	**args;
	char	**cmd_paths;

	args = ft_split(cmd_with_params, ' ');
	cmd = ft_strdup(args[0]);
	cmd_paths = get_cmd_path(envp, cmd);
	exec_cmd(cmd_paths, args, envp);
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