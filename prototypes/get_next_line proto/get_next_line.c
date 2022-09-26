#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	bytesread;
	int			i;
	char		buffer[BUFFER_SIZE + 1];
	char		*content;

	bytesread = 0;
	i = -1;
	content = NULL;
	while (i == -1)
	{
		i = check_new_line(buffer);
		printf("i = %d\n", i);
		bytesread += read(fd, &buffer, BUFFER_SIZE);
		printf("bytesread = %d\n", bytesread);
		buffer[BUFFER_SIZE + 1] = '\0';
		printf("buffer null terminated\n");
		content = ft_append(content, buffer);
		printf("content updated\n");
	}
	return (content);
}

// read until buffer size
// if buffer contains \n, cut string until \n
// malloc array with size of new line
// transfer buffer to a content array
// join everything
// return

int	check_new_line(char *str) //locates new line in a string of text
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