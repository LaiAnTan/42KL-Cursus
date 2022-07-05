#include "libft.h"

int main(void)
{
	int fd;
	char* c;

	fd = open("test.txt", O_WRONLY);
	c = "pizza mozarella";
	printf("fd : %d\n", fd);
	ft_putstr_fd(c, fd);

	return (0);
}