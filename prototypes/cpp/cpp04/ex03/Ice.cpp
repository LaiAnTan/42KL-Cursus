#include "Ice.hpp"

#include <string>
#include <iostream>

using std::cout;
using std::endl;

Ice::Ice(): AMateria("ice")
{
	cout << "Ice: Constructor called" << endl;
	this->type = "ice";
}

Ice::Ice(const Ice &ice): AMateria()
{
	cout << "Ice: Copy constructor called" << endl;
	*this = ice;
}

Ice &Ice::operator = (const Ice &ice)
{
	cout << "Ice: Copy assignment operator called" << endl;
	if (this == &ice)
		return (*this);
	this->type = "ice";
	return (*this);
	
}

Ice::~Ice()
{
	cout << "Ice: Destructor called" << endl;
}

string const &Ice::getType() const
{
	return(this->type);
}

AMateria* Ice::clone() const
{
	return(new Ice());
}

void Ice::use(ICharacter& target)
{
	cout << "Ice: Shoots an ice bolt at " << target.getName() << endl;
}