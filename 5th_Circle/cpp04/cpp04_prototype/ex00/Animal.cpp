#include "Animal.hpp"

#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

Animal::Animal()
{
	cout << "Animal: Default constructor called" << endl;
	this->type = "default";
}

Animal::Animal(string type): type(type)
{
	cout << "Animal: Constructor called" << endl;
}

Animal::Animal(const Animal &animal)
{
	cout << "Animal: Copy constructor called" << endl;
	*this = animal;
}

Animal &Animal::operator = (const Animal &animal)
{
	if (this == &animal)
		return (*this);
	this->type = animal.type;
	return (*this);
}

Animal::~Animal()
{
	cout << "Animal: Destructor called" << endl;
}

string	Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	cout << "Animal: * animal noises *" << endl;
}