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
	cout << "Int constructor called" << endl;
	this->rawVal = num;
}

Fixed::Fixed(const float num)
{
	cout << "Float constructor called" << endl;
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
	return (outs);
}

bool &Fixed::operator < (const Fixed &fixed) const
{
	return (this->rawVal < fixed.getRawBits());
}

bool &Fixed::operator >= (const Fixed &fixed);
bool &Fixed::operator <= (const Fixed &fixed);
bool &Fixed::operator == (const Fixed &fixed);
bool &Fixed::operator != (const Fixed &fixed);

Fixed &operator + (const Fixed &fixed);
Fixed &operator - (const Fixed &Fixed);
Fixed &operator * (const Fixed &fixed);
Fixed &operator / (const Fixed &fixed);

Fixed &operator ++ ();
Fixed &operator ++ (int);
Fixed &operator -- ();
Fixed &operator -- (int);

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

float	Fixed::toFloat(void) const
{
	return ((float) this->rawVal / (float) (1 << this->fBits));
}

int		Fixed::toInt(void) const
{
	return ((int) this->rawVal >> this->fBits);
}