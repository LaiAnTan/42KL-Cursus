#include "pipex.h"

char	*get_path_envp(char **envp)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_strdup("PATH");
	while (envp[i])
	{
		while ((str[j] != '\0') && (str[j] == envp[i][j]))
		{
			j++;
			if (str[j] == '\0' && j == 4)
			{
				free(str);
				return(ft_strdup(envp[i]));
			}
		}
		j = 0;
		i++;
	}
	free(str);
	return (NULL);
}

char	**get_cmd_path(char **envp)
{
	char	*full_path;
	char	**cmd_paths;

	full_path = get_path_envp(envp);
	cmd_paths = ft_split(full_path, ':');
	free(full_path);
	cmd_paths[0] = trim_path(cmd_paths[0]);
	append_slash(cmd_paths);
	return (cmd_paths);
}

char	*trim_path(char *path)
{
	int		i;
	int		j;
	int		len;
	char	*trimmed;

	i = 0;
	j = 5;
	len = ft_strlen(path) - 5; // "PATH="
	trimmed = (char *) malloc (sizeof(char) * (len + 1));
	while (i < len)
	{
		trimmed[i] = path[j];
		i++;
		j++;
	}
	trimmed[i] ='\0';
	free(path);
	return (trimmed);
}

void	append_slash(char **paths)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	while(paths[i])
	{
		len = ft_strlen(paths[i]);
		if (paths[i][len - 1] != '/')
			paths[i] = ft_append(paths[i], "/");
		i++;
	}
}

void	append_cmd(char **paths, char *cmd)
{
	int		i;

	i = 0;
	while(paths[i])
	{
		paths[i] = ft_append(paths[i], cmd);
		i++;
	}
}