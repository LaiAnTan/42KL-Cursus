#include "../../headers/minishell.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (str == NULL)
		return NULL;
	dest = (char *) malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (dest == NULL)
		return (0);
	while (str[i] != '\0')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
		dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, unsigned int end)
{
	char		*str;
	size_t		i;

	i = 0;
	if (!s && start > end)
		return (0);
	if (end >= (unsigned int) ft_strlen(s))
		end = ft_strlen(s);
	if (start >= (unsigned int) ft_strlen(s))
		return (ft_strdup(""));
	str = (char *) malloc(sizeof(char) * ((end - start) + 2));
	if (str == 0)
		return (0);
	while (start <= end && s[start] != '\0')
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_append(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	temp = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1 && s1[i] != '\0')
	{
		temp[i] = s1[i];
		++i;
	}
	while (s2 && s2[j] != '\0')
	{
		temp[i] = s2[j];
		++i;
		++j;
	}
	temp[i] = '\0';
	free(s1);
	return (temp);
}

char	*ft_trimstr(char *source, char to_trim)
{
	char	*ret;
	int		start = 0;
	int		end = ft_strlen(source) - 1;

	if (!source)
		return NULL;
	while (source[start] && source[start] == to_trim)
		++start;
	if (source[start] == '\0')
		ret = ft_strdup("");
	else
	{
		while (end >= 0 && source[end] == to_trim)
		--end;
		ret = ft_substr(source, start, end);
	}
	free(source);
	return (ret);
}