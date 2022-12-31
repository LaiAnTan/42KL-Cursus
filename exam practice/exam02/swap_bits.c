# include <stdio.h>
/*
bitwise AND (&) 
15 in binary = 1111;

octet & 15 >> 4 
moves the first 4 bits to the position of the last 4 bits

octet & 15 << 4
moves the last 4 bits to the position of the first 4 bits

bitwise OR (|)
combines both nibbles
*/
unsigned char	swap_bits(unsigned char octet)
{
	return ((octet & 15) >> 4 | (octet & 15) << 4);
}


int	main(void)
{
	printf("%d\n", swap_bits(2));
}