#include "get_next_line.h"

char    *get_next_line(int fd)
{
    int			i;
	int			bytesread;
    char		buffer[BUFFER_SIZE + 1];
    char		*output;
    char		**temp;
	static char	*content;

	i = -1;
    while (i == -1)
    {
        bytesread = read(fd, &buffer, BUFFER_SIZE);
		if (!bytesread)
			break ;
        buffer[bytesread] = '\0';
        content = ft_append(content, buffer);
		i = check_nl(buffer);
    }
    temp = seperate_nl(content);
    output = ft_strdup(temp[0]);
    content = ft_strdup(temp[1]);
    free(temp);
    return (output);
}

int	check_nl(char *str) //locates new line in a string of text
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
	int		len;
	char	**arr;

	len = ft_strlen(str);
	i = check_nl(str) + 1;
	if (!i)
		i = len;
	j = 0;
	arr = (char**) malloc (sizeof(char) * 2);
	arr[0] = (char *) malloc (sizeof(char) * (i + 1)); // arr[0] = output
	arr[1] = (char *) malloc (sizeof(char) * (len - i + 1)); // arr[1] = content
	while (i)
	{
		arr[0][j++] = *str++;
		i--;
	}
	arr[0][j] = '\0';
	while (*str != '\0')
		arr[1][i++] = *str++;
	arr[1][i] = '\0';
	return (arr);
}

