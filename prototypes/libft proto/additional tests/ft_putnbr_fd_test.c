#include "libft.h"

int main(void)
{
	int fd;
	int c;

	fd = open("test.txt", O_WRONLY);
	c = -2147483648;
	printf("fd : %d\n", fd);
	ft_putnbr_fd(c, fd);
	write(fd, "\n", 1);

	return (0);
}