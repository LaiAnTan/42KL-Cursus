#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int				i;
	int				j;
	unsigned char	bit;

	i = 8;
	j = 0;
	while (i--)
	{
		bit += ((octet >> j) & 1) << i;
		j++;
	}
	return (bit);
}

int	main(void)
{
	printf("%d\n", reverse_bits(38));
}