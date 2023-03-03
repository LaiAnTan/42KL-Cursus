#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i = 0;

	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int		has_nl(char *str, int size)
{
	int	i = 0;
	
	while (i < size && str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*append(char *src, char *dest)
{
	int		i = 0;
	int		j = 0;
	int		size;
	char	*str;
	
	str = malloc(sizeof(char) * (ft_strlen(src) + ft_strlen(dest) + 1));
	if (dest != NULL)
	{
		while (dest[i] != '\0')
		{
			str[i] = dest[i];
			i++;
		}
	}
	if (src != NULL)
	{
		while (src[j] != '\0')
		{
			str[i] = src[j];
			i++;
			j++;
		}
	}
	str[i] = '\0';
	free(dest);
	return (str);
}

char	*get_nl_str(char *line)
{
	int		i = 0;
	int		j = has_nl(line, ft_strlen(line));
	char	*str;

	if (!line)
		return (NULL);
	if (j == -1)
		return (line);
	str = malloc (sizeof(char) * (j + 2)); // 1 byte for \n 1 byte for \0
	while (i <= j)
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*skip(char *line)
{
	int		j = 0;
	int		i  = has_nl(line, ft_strlen(line));
	char	*str;

	if (i == -1)
		return (NULL); //no ln found
	else
		i++; // to skip \n
		
	str = malloc(sizeof(char) * (ft_strlen(line) - i + 1));
	while (i < ft_strlen(line))
	{
		str[j] = line[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free(line);
	return (str);
}

char	*get_next_line(int fd)
{
	int			bytes = 0;
	char		buffer[BUFFER_SIZE + 1];
	char		*ret_str = NULL;
	static char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (has_nl(buffer, bytes) == -1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (!bytes || bytes == -1)
			break;
		buffer[bytes] = '\0';
		line = append(buffer, line);
	}

	if (!line)
		return (NULL);
	ret_str = get_nl_str(line);
	if (!ret_str)
		return (NULL);
	line = skip(line);
	return (ret_str);

}

int main(void)
{
	int fd = open("test.txt", O_RDWR);
	char	*line;
	for (int i = 0; i < 7; i++)
	{
		line = get_next_line(fd);
		printf("str: %s", line);
		free(line);
	}
	
}