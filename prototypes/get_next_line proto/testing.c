#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	char *a = "testing test";
	char *b = " testicles";
	printf("src1: %s\n", a);
	printf("src2: %s\n", b);
	printf("appended: %s\n", ft_append(a, b));

	int fd;
	fd = open("test.txt", O_RDONLY);
	printf("fd = %d\n", fd);
	printf("%s", get_next_line(fd));
}
	// char *str = (char *) malloc (sizeof(char) * 100);
	// int	size;
	// size = read(fd, str, 12);
	// printf("size = %d\n", size);
	// str[size] = '\0';
	// printf("read:\n%s\n", str);