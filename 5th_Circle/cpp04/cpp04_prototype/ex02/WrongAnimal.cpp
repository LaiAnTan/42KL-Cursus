#include "WrongAnimal.hpp"

#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

WrongAnimal::WrongAnimal()
{
	cout << "WrongAnimal: Default constructor called" << endl;
	this->type = "default";
}

WrongAnimal::WrongAnimal(string type): type(type)
{
	cout << "WrongAnimal: Constructor called" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
	cout << "WrongAnimal: Copy constructor called" << endl;
	*this = WrongAnimal;
}

WrongAnimal &WrongAnimal::operator = (const WrongAnimal &WrongAnimal)
{
	if (this == &WrongAnimal)
		return (*this);
	this->type = WrongAnimal.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal: Destructor called" << endl;
}

string	WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	cout << "WrongAnimal: * Muffled sounds of animal violence *" << endl;
}