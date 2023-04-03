#include "AAnimal.hpp"

#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

AAnimal::AAnimal()
{
	cout << "Animal: Default constructor called" << endl;
	this->type = "default";
}

AAnimal::AAnimal(string type): type(type)
{
	cout << "Animal: Constructor called" << endl;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	cout << "Animal: Copy constructor called" << endl;
	*this = animal;
}

AAnimal &AAnimal::operator = (const AAnimal &animal)
{
	if (this == &animal)
		return (*this);
	this->type = animal.type;
	return (*this);
}

AAnimal::~AAnimal()
{
	cout << "Animal: Destructor called" << endl;
}

string	AAnimal::getType(void) const
{
	return (this->type);
}