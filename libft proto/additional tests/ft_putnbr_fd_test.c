#include "libft.h"

int main(void)
{
	int fd;
	int c;
	int d;

	fd = open("test.txt", O_WRONLY);
	c = 12345;
	d = -12345;
	printf("fd : %d\n", fd);
	ft_putnbr_fd(c, fd);
	write(fd, "\n", 1);
	ft_putnbr_fd(d, fd);

	return (0);
}