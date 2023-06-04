#include "Cure.hpp"

#include <string>
#include <iostream>

using std::cout;
using std::endl;

Cure::Cure(): AMateria("cure")
{
	cout << "Cure: Constructor called" << endl;
	this->type = "cure";
}

Cure::Cure(const Cure &cure): AMateria()
{
	cout << "Cure: Copy constructor called" << endl;
	*this = cure;
}

Cure &Cure::operator = (const Cure &cure)
{
	cout << "Cure: Copy assignment operator called" << endl;
	if (this == &cure)
		return (*this);
	this->type = "cure";
	return (*this);
}

Cure::~Cure()
{
	cout << "Cure: Destructor called" << endl;
}

string const &Cure::getType() const
{
	return (this->type);
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	cout << "Cure: Heals " << target.getName() << "'s wounds" << endl;
}