#include "Dog.hpp"

#include <string>
#include <iostream>

using	std::string;
using	std::endl;
using	std::cout;

Dog::Dog(): Animal()
{
	cout << "Dog: Default constructor called" << endl; 
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &dog): Animal(dog)
{
	cout << "Dog: Copy constructor called" << endl;
	*this = dog;
}

Dog	&Dog::operator = (const Dog &dog)
{
	cout << "Dog: Copy assignment operator called" << endl; 
	if (this == &dog)
		return (*this);
	this->type = "Dog";
	this->brain = dog.brain;
	return (*this);
}

Dog::~Dog()
{
	cout << "Dog: Destructor called" << endl;
}

void	Dog::makeSound(void) const
{
	cout << "Dog: * Woof! *" << endl;
}