#include "libft.h"

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	printf(" \n");
}

static void		check_strnstr(char *big, char *little, int len)
{
	const char *str;

	if (!(str = ft_strnstr(big, little, len)))
		ft_print_result("NULL");
	else
		ft_print_result(str);
}

int main(void)
{
	check_strnstr("lorem ipsum dolor sit amet", "lorem", 15);
	check_strnstr("lorem ipsum dolor sit amet", "ipsum", 15);
	check_strnstr("lorem ipsum dolor sit amet", "dolor", 15);
	return (0);
}