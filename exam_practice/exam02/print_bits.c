# include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 8;
	while (--i >= 0)
	{
		bit = ((octet >>= 1) & 1) + '0';
		write(STDOUT_FILENO, &bit, 1);
	}
}


int	main()
{
	print_bits(212);
}