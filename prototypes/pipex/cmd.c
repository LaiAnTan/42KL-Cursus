#include "pipex.h"

void	run_cmd(char *cmd_with_params, char **envp)
{
	char	*cmd;
	char	**args;
	char	**cmd_paths;

	args = ft_split(cmd_with_params, ' ');
	free(cmd_with_params);
	cmd = ft_strdup(args[0]);
	cmd_paths = get_cmd_path(envp, cmd);
	exec_cmd(cmd, cmd_paths, args, envp);
}

void	free_2d_array(char **a)
{
	int		i;

	i = 0;
	while (a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
}

int	exec_cmd(char *cmd, char **cmd_paths, char **args, char **envp)
{
	int		i;
	int		status;

	i = 0;
	while (cmd_paths[i])
	{
		args[0] = ft_strdup(cmd_paths[i]);
		status = access(args[0], X_OK);
		if (!status)
		{
			if (execve(cmd_paths[i], args, envp) == -1)
			{
				free_2d_array(cmd_paths);
				free_2d_array(args);
				free_2d_array(envp);
				error(cmd, "command execution failed");
			}
		}
		else
			i++;
		if (args[0])
			free(args[0]);
	}
	free_2d_array(cmd_paths);
	free_2d_array(args);
	free_2d_array(envp);
	error(cmd, "command not found");
	return (-1);
}