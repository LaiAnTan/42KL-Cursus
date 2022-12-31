# include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (octet >> i & 1) + '0';
		write(STDOUT_FILENO, &bit, 1);
		i--;
	}
}


int	main()
{
	print_bits(212);
}