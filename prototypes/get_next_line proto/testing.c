#include <stdio.h>
#include <time.h>
#include "get_next_line.h"

int main(void)
{
	// char *arr = "this is the first line\nthis is the second line";
	// char **temp = seperate_nl(arr);
	// printf("t1: %s\n", temp[1]);
	// printf("t2: %s\n", temp[2]);

	int fd1;
	int fd2;
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	printf("fd1 = %d\n", fd1);
	printf("fd2 = %d\n", fd2);
	printf("file 1 line 1 output: %s", get_next_line(fd1));
	printf("file 2 line 1 output: %s", get_next_line(fd2));
	printf("file 1 line 2 output: %s", get_next_line(fd1));
	printf("file 2 line 2 output: %s", get_next_line(fd2));
	printf("file 1 line 3 output: %s", get_next_line(fd1));
	printf("file 2 line 3 output: %s", get_next_line(fd2));

	return (0);
}
	
