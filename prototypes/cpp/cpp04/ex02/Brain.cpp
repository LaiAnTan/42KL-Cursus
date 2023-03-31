#include "Brain.hpp"

#include <iostream>
#include <string>

using	std::string;
using	std::cout;
using	std::endl;

Brain::Brain()
{
	cout << "Brain: Default constructor called" << endl;
}

Brain::Brain(const Brain &brain)
{
	cout << "Brain: Copy constructor called" << endl;
	*this = brain;
}

Brain &Brain::operator = (const Brain &brain)
{
	cout << "Brain: Copy assignment operator called" << endl;
	if (this == &brain)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	cout << "Brain: Destructor called" << endl;
}