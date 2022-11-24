#include "libft.h"

int main(void)
{
	int fd;
	char c;

	fd = open("test.txt", O_WRONLY);
	c = 'a';
	printf("fd : %d\n", fd);
	ft_putchar_fd(c, fd);

	return (0);
}