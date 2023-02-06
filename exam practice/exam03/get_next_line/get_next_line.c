#include "get_next_line.h"

#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char buf[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read(fd, &buf, BUFFER_SIZE);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}

/*
gnl
check fd < 0 & buffer size <= 0
malloc buffer
read from file
transfer


*/