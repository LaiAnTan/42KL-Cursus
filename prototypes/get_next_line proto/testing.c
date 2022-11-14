#include <stdio.h>
#include <time.h>
#include "get_next_line.h"

int main(void)
{
	int fd1;
	fd1 = open("test.txt", O_RDONLY);
	printf("fd1 = %d\n", fd1);
	
	char *arr = get_next_line(fd1);
	printf("output: %s\n", arr);
	free(arr);
	return (0);
}
