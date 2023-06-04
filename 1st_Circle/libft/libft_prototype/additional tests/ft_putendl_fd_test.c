#include "libft.h"

int main(void)
{
	int fd;
	char *c;
	char *d;

	fd = open("test.txt", O_WRONLY);
	c = "pizza mozarella";
	d = "yum";
	printf("fd : %d\n", fd);
	ft_putendl_fd(c, fd);
	for (int i = 0; i < 3; i++)
		write(fd, &d[i], 1);

	return (0);
}