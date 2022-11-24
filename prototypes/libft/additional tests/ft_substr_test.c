#include "libft.h"

static void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	printf("\n");
}

static void		check_substr(char *str, int start, int len)
{
	char	*substr;

	if (!(substr = ft_substr(str, start, len)))
		ft_print_result("NULL");
	else
		ft_print_result(substr);
	if (str == substr)
		ft_print_result("\nA new string was not returned");
	else
		free(substr);
}

int main(void)
{
	char	str[] = "lorem ipsum dolor sit amet";
	check_substr(str, 7, 10);
	check_substr(str, 7, 0);
	return (0);
}