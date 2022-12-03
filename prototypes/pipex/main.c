#include "pipex.h"

/*
call 			: ./pipex infile "ls -l" "wc -l" outfile
behaves like 	: < infile ls -l | wc -l > outfile
*/

// char *args[3] = {"/bin/ls", "-l", NULL};
// if (execve(args[0], args, envp))
// 	perror("error");

int	main(int argc, char **argv, char **envp)
{
	char	*cmd;
	char	**str;

	str = ft_split(argv[2], ' ');
	cmd = ft_strdup(str[0]);
	char **cmd_path = get_cmd_path(envp, cmd);
	run_cmd(cmd_path, str, envp);
	free(cmd);
	for(int i = 0; str[i]; i++)
		free(str[i]);
	free(str);
	for(int i = 0; cmd_path[i]; i++)
		free(cmd_path[i]);
	free(cmd_path);
}

int	run_cmd(char **cmd_paths, char **args, char **envp)
{
	int		i;
	int		status;

	i = 0;
	while (cmd_paths[i])
	{
		free(args[0]);
		args[0] = ft_strdup(cmd_paths[i]);
		printf("now checking %s path\n", args[0]);
		status = execve(cmd_paths[i], args, envp);
		if (status)
			i++;
	}
	return (-1);
}