#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	char *str = (char *) malloc (sizeof(char) * 100);
	int	size;
	int fd;
	fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	size = read(fd, str, 12);
	printf("size = %d\n", size);
	str[size] = '\0';
	printf("read:\n%s\n", str);
}

