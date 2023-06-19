/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:31:45 by tlai-an           #+#    #+#             */
/*   Updated: 2023/06/16 10:37:18 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int	determine_error(void)
{
	if (errno == ENOTDIR)
		error_msg("cd", NULL, "Not a directory", 1);
	else if (errno == ENOENT)
		error_msg("cd", NULL, "No such file or directory", 1);
	return (1);
}

void	cd_update_env(t_data *data)
{
	t_list	*node;

	node = find_var(data->vars, "OLDPWD");
	if (node == NULL)
	{
		node = ft_lstnew_env(ft_append(ft_strdup("OLDPWD="), data->cwd));
		ft_lstadd_back(&data->vars, node);
	}
	else
		node->env.str = ft_append(ft_strdup("OLDPWD="), data->cwd);
	free(data->cwd);
	data->cwd = getcwd(NULL, 1024);
	node = find_var(data->vars, "PWD");
	if (node == NULL)
	{
		node = ft_lstnew_env(ft_append(ft_strdup("PWD="), data->cwd));
		ft_lstadd_back(&data->vars, node);
	}
	else
		node->env.str = ft_append(ft_strdup("PWD="), data->cwd);
}

char	*cd_get_cd_path(int size, char **args, t_data *data)
{
	char	*cd_path;

	cd_path = NULL;
	if (size == 1 || args[1][0] == '~')
	{
		cd_path = access_var(data, "HOME");
		if (ft_strlen(cd_path) == 0)
		{
			error_msg("cd", NULL, "HOME not set", 1);
			return (NULL);
		}
	}
	else if (args[1][0] == '-')
	{
		cd_path = access_var(data, "OLDPWD");
		if (ft_strlen(cd_path) == 0)
		{
			error_msg("cd", NULL, "OLDPWD not set", 1);
			return (NULL);
		}
		printf("%s\n", cd_path);
	}
	else
		cd_path = ft_strdup(args[1]);
	return (cd_path);
}

int	builtin_cd(char **args, t_data *data)
{
	int			size;
	char		*cd_path;

	size = count_2d_array(args);
	cd_path = NULL;
	if (size > 2)
		return (error_msg("cd", NULL, "too many arguments", 1));
	cd_path = cd_get_cd_path(size, args, data);
	if (!cd_path)
		return (1);
	if (chdir(cd_path) == -1)
		return (determine_error());
	cd_update_env(data);
	return (0);
}
