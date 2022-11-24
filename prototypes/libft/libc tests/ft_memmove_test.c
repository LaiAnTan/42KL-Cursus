#include "libft.h"

static void		check_memmove(void *dest, void *src, int n)
{
	if (dest != ft_memmove(dest, src, n))
		write(1, "dest's adress was not returned\n", 31);
	write(1, dest, 22);
}

int main(void)
{
	char	src[] = "lorem ipsum dolor sit amet";
	char	*dest = NULL;

	printf("String: (%s)\n", src);
	check_memmove(src, dest, 8);
	printf("\n");
	return (0);
}