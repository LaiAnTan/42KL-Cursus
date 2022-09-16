#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	bytesread;
	int			i;
	char		buffer[BUFFER_SIZE + 1];
	char		*content;

	bytesread = 0;
	i = 0;
	while (!check_new_line(buffer))
	{
		bytesread += read(fd, &buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE + 1] = '\0';
		content = ft_append(buffer, content);
	}
	return (content);
}

// read until new line
// malloc array with size of new line
// transfer buffer to a content array
// join everything
// return

int	check_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}