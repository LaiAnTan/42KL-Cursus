#include "Fixed.hpp"

#include <iostream>
#include <cmath>

using	std::cout;
using	std::endl;

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	this->rawVal = 0;
}

Fixed::Fixed(const int num)
{
	this->rawVal = num;
}

Fixed::Fixed(const float num)
{
	this->rawVal = roundf(num * (1 << fBits));
}

Fixed::Fixed(const Fixed &toCopy)
{
	cout <<  "Copy constructor called" << endl;
	*this = toCopy;
}

Fixed	&Fixed::operator = (const Fixed &toCopy)
{
	cout << "Copy assignment operator called" << endl;
	if (this == &toCopy)
		return (*this);
	this->rawVal = toCopy.getRawBits();
	return (*this);
}

ostream &operator << (ostream &outs, const Fixed &fixed)
{
	outs << fixed.toFloat();
}

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

int	Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (this->rawVal);
}

void	Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called" << endl;
	this->rawVal = raw;
}

float	Fixed::toFloat(void)
{
	return ((float) this->rawVal / (float) (1 << this->fBits));
}

int		Fixed::toInt(void)
{
	return ((int) this->rawVal >> this->fBits);
}