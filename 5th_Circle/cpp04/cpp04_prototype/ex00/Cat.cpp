#include "Cat.hpp"

#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

Cat::Cat(): Animal()
{
	cout << "Cat: Default constructor called" << endl;
	this->type = "Cat";
}

Cat::Cat(const Cat &cat): Animal(cat)
{
	cout << "Cat: Copy constructor called" << endl;
	*this = cat;
}

Cat &Cat::operator = (const Cat &cat)
{
	cout << "Cat: Copy assignment operator called" << endl;
	if (this == &cat)
		return (*this);
	this->type = "Cat";
	return (*this);
}

Cat::~Cat()
{
	cout << "Cat: Destructor called" << endl;
}

void	Cat::makeSound(void) const
{
	cout << "Cat: * Meowwww *" << endl;
}