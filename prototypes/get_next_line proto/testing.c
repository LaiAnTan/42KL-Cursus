#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
		// char *str = (char *) malloc (sizeof(char) * 100);
		// int	size;
		// int fd;
		// fd = open("test.txt", O_RDONLY);
		// printf("fd = %d\n", fd);
		// size = read(fd, str, 12);
		// printf("size = %d\n", size);
		// str[size] = '\0';
		// printf("read:\n%s\n", str);

	char *a = "foo";
	char *b = " bar baz";
	b = ft_append(a, b);

	printf("%s ", b);
}

