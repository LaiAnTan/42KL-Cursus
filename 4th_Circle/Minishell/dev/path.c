#include "../headers/minishell.h"

char	*get_path_envp(t_data *data)
{
	char	*str;
	t_list	*lst;

	str = ft_strdup("PATH=");
	lst = data->vars;
	while (lst != NULL)
	{
		if (ft_strcmp_equals(str, lst->env.str) == 0)
		{
			free(str);
			return (ft_strdup(lst->env.str));
		}
		lst = lst->next;
	}
	free(str);
	return (NULL);
}

char	**get_cmd_path(t_data *data, char *cmd)
{
	char	*full_path;
	char	**cmd_paths;

	full_path = get_path_envp(data);
	// printf("full path = %s\n", full_path);
	cmd_paths = ft_split(full_path, ':');
	// for (int i = 0; cmd_paths[i]; i++)
	// 	printf("%d =  %s\n", i, cmd_paths[i]);
	free(full_path);
	cmd_paths[0] = trim_path(cmd_paths[0]);
	append_stuff(cmd_paths, cmd);
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
	len = ft_strlen(path) - 5;
	trimmed = (char *) malloc (sizeof(char) * (len + 1));
	while (i < len)
	{
		trimmed[i] = path[j];
		i++;
		j++;
	}
	trimmed[i] = '\0';
	free(path);
	return (trimmed);
}

void	append_stuff(char **paths, char *cmd)
{
	int		i;
	int		j;
	int		len;
	char	*to_append;

	i = 1;
	j = 0;
	len = ft_strlen(cmd);
	to_append = (char *) malloc (sizeof(char) * len + 2);
	to_append[0] = '/';
	while (j < len)
		to_append[i++] = cmd[j++];
	to_append[len + 1] = '\0';
	i = 0;
	while (paths[i])
	{
		len = ft_strlen(paths[i]);
		if (paths[i][len - 1] == '/')
			paths[i] = ft_append(paths[i], cmd);
		else
			paths[i] = ft_append(paths[i], to_append);
		i++;
	}
	free(to_append);
}