#ifndef FIXED_HPP

#define FIXED_HPP

class	Fixed
{
	public:
				Fixed();
				Fixed(const Fixed &fixed);
				Fixed &operator=(const Fixed &fixed);
				~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	private:
		int					val;
		static const int	fBits = 8;
};

#endif