#include "libft.h"

static void		ft_print_result(int n)
{
	if (n > 0)
		write(1, "1", 1);
	else if (n < 0)
		write(1, "-1", 2);
	else
		write(1, "0", 1);
	printf("\n");
}

int main(void)
{
	ft_print_result(ft_strncmp("test", "testss", 7)); 		// -1
	ft_print_result(ft_strncmp("testss", "test", 7)); 		// 1
	ft_print_result(ft_strncmp("", "test", 4));				// -1
	ft_print_result(ft_strncmp("test", "", 4));				// 1
	ft_print_result(ft_strncmp("test\200", "test\0", 6));	// 1
	return (0);
}