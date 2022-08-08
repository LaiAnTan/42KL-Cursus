#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int n = 15;
	char a = 'e';
	uint32_t s = &a;
	//p test
	printf("%p\n", (n));
	printf("%p\n", (&n));
	printf("%p\n", (&a));
	
	printf("\n");

	//test if specifier is valid
	printf("%www\n");
	printf("%5www\n"); // number of spaces that the first char takes up
	printf("%#+  wdj");

	// % and all flags behind are skipped 

	// numbers b4 diuxX test
	printf("%d\n", 2);
	printf("%5d\n", 2); // number of spaces that number takes up

	// "# +" flags test
	printf("%x\n", n);
	printf("%#x\n", n); // 0x in front
	printf("%#X\n", n); // 0X in front 

	printf("%   d\n", n);
	printf("% +d\n", n); // shows the sign
	printf("%+ d\n", n); // + sign overrides space if both used

	// undefined behaviour: "#+" "# "  
	return (0);
}