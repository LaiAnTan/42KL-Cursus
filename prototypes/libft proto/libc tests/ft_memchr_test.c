#include "libft.h"

static void		ft_print_result(const char *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	write(1, "\n", 1);
}

static void		check_memchr(void *s, char c, int n)
{
	const char *str;

	str = ft_memchr(s, c, n);
	if (!str)
		ft_print_result("NULL");
	else
		ft_print_result(str);
}

int main(void)
{
	check_memchr("bonjour", 'b', 4);
	check_memchr("bonjour", 'o', 7);
	check_memchr("bonjourno", 'n', 2);

	return(0);
}