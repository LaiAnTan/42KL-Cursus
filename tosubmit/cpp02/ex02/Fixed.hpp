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

		bool operator > (const Fixed &fixed) const;
		bool operator < (const Fixed &fixed) const;
		bool operator >= (const Fixed &fixed) const;
		bool operator <= (const Fixed &fixed) const;
		bool operator == (const Fixed &fixed) const;
		bool operator != (const Fixed &fixed) const;

		Fixed operator + (const Fixed &fixed) const;
		Fixed operator - (const Fixed &Fixed) const;
		Fixed operator * (const Fixed &fixed) const;
		Fixed operator / (const Fixed &fixed) const;

		// pre ++a;
		Fixed &operator ++ ();
		Fixed &operator -- ();

		// post a++;
		Fixed operator ++ (int);
		Fixed operator -- (int);

		~Fixed();
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		static Fixed &min(Fixed &fp1, Fixed &fp2);
		static Fixed min(const Fixed &fp1, const Fixed &fp2);
		static Fixed &max(Fixed &fp1, Fixed &fp2);
		static Fixed max(const Fixed &fp1, const Fixed &fp2);

	private:
		int					rawVal;
		static const int	fBits = 8;
};

ostream &operator << (ostream &outs, const Fixed &fixed);

#endif