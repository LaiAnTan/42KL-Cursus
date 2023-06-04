#ifndef FIXED_HPP

#define FIXED_HPP

#include <iostream>

using	std::ostream;

class	Fixed
{
	public:
		Fixed();
		Fixed(const int num);
		Fixed(const float num);
		Fixed(const Fixed &fixed);

		Fixed &operator = (const Fixed &fixed);
		
		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int		toInt(void) const;
		float	toFloat(void) const;
	private:
		int					rawVal;
		static const int	fBits = 8;
};

ostream &operator << (ostream &outs, const Fixed &fixed);

#endif