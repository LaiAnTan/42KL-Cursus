#include <stdio.h>
#include <time.h>
#include "get_next_line.h"

int main(void)
{
	int fd1;
	char *test;
	fd1 = open("test.txt", O_RDONLY);
	printf("fd1 = %d\n", fd1);
	test = NULL;
	for (int i = 0; i < 6; i++)
	{
		if (test)
			free(test);
		test = get_next_line(fd1);
		printf("output: %s\n", test);
	}
	return (0);
}
