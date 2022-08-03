#include <stdio.h>

int	main(void)
{
	int n = 15;

	printf("%x\n", n);
	printf("%#x\n", n); // 0x in front
	printf("%#X\n", n); // 0X in front 

	printf("%   d\n", n);
	printf("% +d\n", n); // shows the sign
	printf("%+ d\n", n); // + sign overrides space if both used
	return (0);
}