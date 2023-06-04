#include "pipex.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str;
	size_t i;

    i = -1;
    str = (char *) malloc(sizeof(char) * len + 1);
    if (str == 0)
        return (0);
    while (++i < len && s[start])
    {
        str[i] = s[start];
        start++;
    }
	str[i] = '\0';
    return (str);
}

int	ft_strcmp(char *line, char *limiter)
{
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n' && limiter[i] != '\0')
	{
		if (line[i] != limiter[i])
			return (-1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_append(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	temp = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s1 != NULL)
	{
		while (s1[j] != '\0')
			temp[i++] = s1[j++];
	}
	if (s2 != NULL)
	{
		while (*s2 != '\0')
			temp[i++] = *s2++;
	}
	temp[i] = '\0';
	free(s1);
	return (temp);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (!str)
		return (NULL);
	dest = (char *) malloc (sizeof(char) * (ft_strlen(str) + 1));
	if (!dest)
		return (NULL);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}