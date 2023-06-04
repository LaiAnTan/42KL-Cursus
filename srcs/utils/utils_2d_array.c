#include "../../headers/minishell.h"

void	free_2d_array(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i] != NULL)
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
	(*arr) = NULL;
}

int	count_2d_array(char **e)
{
	int	i;

	i = 0;
	while (e[i])
		++i;
	return (i);
}

char	**realloc_append(char **src, char *str)
{
	int		i;
	int		len;
	char	**new;

	i = 0;
	len = 0;
	if (!str)
		return src;
	while (src[len] != NULL)
		len++;
	new = (char **) malloc (sizeof(char *) * (len + 2));
	if (!new)
		return (NULL);
	while (i < len)
	{
		new[i] = ft_strdup(src[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	free_2d_array(&src);
	return (new);
}