#include "libft.h"

static void		ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write (1, &c, 1);
}

static void		check_strlcat(char *dest, char *src, int size, int dest_len)
{
	ft_print_result(ft_strlcat(dest, src, size));
	write(1, "\n", 1);
	write(1, dest, dest_len);
	free(dest);
}

int main(void)
{

	char	*dest;
	int		dest_len;

	alarm(5);
	dest_len = 15;
	if (!(dest = (char *)malloc(sizeof(*dest) * dest_len)))
		return (0);
	memset(dest, 0, dest_len);
	memset(dest, 'r', 6);
	
	dest[10] = 'a';
	printf("String: %s\n", dest);
	check_strlcat(dest, "lorem ipsum dolor sit amet", 0, dest_len);

	return (0);
}