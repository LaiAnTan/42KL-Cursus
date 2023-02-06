#include "WrongCat.hpp"

#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

WrongCat::WrongCat(): WrongAnimal()
{
	cout << "WrongCat: Default constructor called" << endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &WrongCat): WrongAnimal(WrongCat)
{
	cout << "WrongCat: Copy constructor called" << endl;
	*this = WrongCat;
}

WrongCat &WrongCat::operator = (const WrongCat &WrongCat)
{
	cout << "WrongCat: Copy assignment operator called" << endl;
	if (this == &WrongCat)
		return (*this);
	this->type = "WrongCat";
	return (*this);
}

WrongCat::~WrongCat()
{
	cout << "WrongCat: Destructor called" << endl;
}

void	WrongCat::makeSound(void) const
{
	cout << "WrongCat: * This shouldn't be printed *" << endl;
}