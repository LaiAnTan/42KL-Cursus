#include "../../headers/minishell.h"


/*
function that locates the PATH env variable from the linked list of env variables and then returns it
*/
char	*get_path_envp(t_data *data)
{
	t_list	*lst;

	lst = data->vars;
	while (lst != NULL)
	{
		if (ft_strcmp_equals(lst->env.str, "PATH") == 0)
			return (ft_strdup(lst->env.str));
		lst = lst->next;
	}
	return (NULL);
}

/*
function that checks if a string is in the format of an executable
*/
int		is_executable(char *str)
{
	if (ft_strlen(str) > 2 && str[0] == '.' && str[1] == '/')
		return (1);
	return (0);
}

/*
function that gets all the possible paths of a command if it is not an executable
*/
char	**get_cmd_path(t_data *data, char *cmd)
{
	char	*full_path;
	char	**cmd_paths;

	if (is_executable(cmd))
	{
		cmd_paths = (char **) malloc(sizeof(char *) * 2);
		cmd_paths[0] = ft_strdup(cmd);
		cmd_paths[1] = NULL;
	}
	else
	{
		full_path = get_path_envp(data);
		if (!full_path)
			return (NULL);
		cmd_paths = ft_split(full_path, ':');
		free(full_path);
		cmd_paths[0] = trim_path(cmd_paths[0]);
		append_stuff(cmd_paths, cmd);
	}
	return (cmd_paths);
}

/*
function that trims the string "PATH=" from the front of a path
*/
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

/*
function that appends the command name at the end of the path
*/
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