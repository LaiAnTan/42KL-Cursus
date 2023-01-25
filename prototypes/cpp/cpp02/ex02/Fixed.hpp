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

		bool &operator > (const Fixed &fixed) const;
		bool &operator < (const Fixed &fixed) const;
		bool &operator >= (const Fixed &fixed) const;
		bool &operator <= (const Fixed &fixed) const;
		bool &operator == (const Fixed &fixed) const;
		bool &operator != (const Fixed &fixed) const;

		Fixed &operator + (const Fixed &fixed);
		Fixed &operator - (const Fixed &Fixed);
		Fixed &operator * (const Fixed &fixed);
		Fixed &operator / (const Fixed &fixed);

		Fixed &operator ++ ();
		Fixed &operator ++ (int);
		Fixed &operator -- ();

		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					rawVal;
		static const int	fBits = 8;
};

ostream &operator << (ostream &outs, const Fixed &fixed);

#endif