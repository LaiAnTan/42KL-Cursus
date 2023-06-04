#include "Fixed.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

Fixed::Fixed()
{
	cout << "Default constructor called" << endl;
	this->val = 0;
}

Fixed::Fixed(const Fixed &toCopy)
{
	cout <<  "Copy constructor called" << endl;
	*this = toCopy;
}

Fixed	&Fixed::operator=(const Fixed &toCopy)
{
	cout << "Copy assignment operator called" << endl;
	if (this == &toCopy)
		return (*this);
	this->val = toCopy.getRawBits();
	return (*this);
};

Fixed::~Fixed()
{
	cout << "Destructor called" << endl;
}

int	Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called" << endl;
	return (this->val);
}

void	Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called" << endl;
	this->val = raw;
}