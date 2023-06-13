#include "Cat.hpp"

#include <string>
#include <iostream>

using	std::string;
using	std::cout;
using	std::endl;

Cat::Cat(): AAnimal()
{
	cout << "Cat: Default constructor called" << endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &cat): AAnimal(cat)
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
	this->brain = new Brain();
	*(this->brain) = *(cat.brain);
	return (*this);
}

Cat::~Cat()
{
	cout << "Cat: Destructor called" << endl;
	delete this->brain;
}

void	Cat::makeSound(void) const
{
	cout << "Cat: * Meowwww *" << endl;
}