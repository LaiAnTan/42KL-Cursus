/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai-an <tlai-an@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:13:31 by tlai-an           #+#    #+#             */
/*   Updated: 2023/01/10 14:19:30 by tlai-an          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
				return (ft_strdup(envp[i]));
			}
		}
		j = 0;
		i++;
	}
	free(str);
	return (NULL);
}

char	**get_cmd_path(char **envp, char *cmd)
{
	char	*full_path;
	char	**cmd_paths;

	full_path = get_path_envp(envp);
	cmd_paths = ft_split(full_path, ':');
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
