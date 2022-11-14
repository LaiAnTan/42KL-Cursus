#include "get_next_line.h"

char	*get_next_line(int fd)
{
    char			*buffer;
    char			*output;
    char			**temp;
	static char		*content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
    content = transfer(fd, content, buffer); //!!
	if (!content)
		return (NULL);
	else
		temp = seperate_nl(content);
    output = ft_strdup(temp[0]);
    content = ft_strdup(temp[1]);
	if (*content == '\0')
	{
		free(content);
		content = NULL;
	}
	free(temp[0]);
	free(temp[1]);
	free(temp);
    return (output);
}

int	check_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	**seperate_nl(char *str)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	**arr;

	len = ft_strlen(str);
	i = check_nl(str) + 1;
	if (!i)
		i = len;
	j = 0;
	k = 0;
	arr = (char**) malloc (sizeof(char) * 2);
	arr[0] = (char *) malloc (sizeof(char) * (i + 1));
	arr[1] = (char *) malloc (sizeof(char) * (len - i + 1));
	while (i)
	{
		arr[0][j++] = str[k++];
		i--;
	}
	arr[0][j] = '\0';
	while (str[k] != '\0')
		arr[1][i++] = str[k++];
	arr[1][i] = '\0';
	free(str);
	return (arr);
}

char *transfer(int fd, char *content, char *buffer)
{
	int	bytesread;

	while (check_nl(buffer) == -1)
    {
        bytesread = read(fd, buffer, BUFFER_SIZE);
		if (!bytesread)
			break ;
		if (bytesread == -1)
			break ;
        buffer[bytesread] = '\0';
        content = ft_append(content, buffer);
    }
	free(buffer);
	return (content);
}