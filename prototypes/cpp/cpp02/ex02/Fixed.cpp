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

bool Fixed::operator > (const Fixed &fixed) const
{
	return (this->rawVal > fixed.rawVal);
}

bool Fixed::operator < (const Fixed &fixed) const
{
	return (this->rawVal < fixed.rawVal);
}

bool Fixed::operator >= (const Fixed &fixed) const
{
	return (this->rawVal >= fixed.rawVal);
}

bool Fixed::operator <= (const Fixed &fixed) const
{
	return (this->rawVal <= fixed.rawVal);
}

bool Fixed::operator == (const Fixed &fixed) const
{
	return (this->rawVal == fixed.rawVal);
}

bool Fixed::operator != (const Fixed &fixed) const
{
	return (this->rawVal != fixed.rawVal);
}

Fixed &Fixed::operator + (const Fixed &fixed)
{
	this->rawVal += fixed.rawVal;
	return (*this);
}

Fixed &Fixed::operator - (const Fixed &fixed)
{
	this->rawVal -= fixed.rawVal;
	return (*this);
}

Fixed &Fixed::operator * (const Fixed &fixed)
{
	this->rawVal *= fixed.rawVal;
	return (*this);
}

Fixed &Fixed::operator / (const Fixed &fixed)
{
	this->rawVal /= fixed.rawVal;
	return (*this);
}


Fixed &Fixed::operator ++ ()
{
	++this->rawVal;
	return (*this);
}

Fixed Fixed::operator ++ (int)
{
	Fixed temp(*this);
	++this->rawVal;
	return (temp);
}

Fixed &Fixed::operator -- ()
{
	--this->rawVal;
	return (*this);
}

Fixed Fixed::operator -- (int)
{
	Fixed temp(*this);
	++this->rawVal;
	return (temp);
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

float	Fixed::toFloat(void) const
{
	return ((float) this->rawVal / (float) (1 << this->fBits));
}

int		Fixed::toInt(void) const
{
	return ((int) this->rawVal >> this->fBits);
}

Fixed &Fixed::min(Fixed &fp1, Fixed &fp2)
{
	if (fp1.rawVal < fp2.rawVal)
		return (fp1);
	else
		return (fp2);
}

Fixed Fixed::min(const Fixed &fp1, const Fixed &fp2)
{
	if (fp1.rawVal < fp2.rawVal)
		return (fp1);
	else
		return (fp2);
}

Fixed &Fixed::max(Fixed &fp1, Fixed &fp2)
{
	if (fp1.rawVal > fp2.rawVal)
		return (fp1);
	else
		return (fp2);
}

Fixed Fixed::max(const Fixed &fp1, const Fixed &fp2)
{
	if (fp1.rawVal > fp2.rawVal)
		return (fp1);
	else
		return (fp2);
}

ostream &operator << (ostream &outs, const Fixed &fixed)
{
	outs << fixed.toFloat();
	return (outs);
}