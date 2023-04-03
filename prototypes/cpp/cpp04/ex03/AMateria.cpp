#include "AMateria.hpp"

#include <string>
#include <iostream>

using std::string;
using std::endl;
using std::cout;

AMateria::AMateria()
{
	cout << "AMateria: Default constuctor called" << endl;
	this->type = "default";
}

AMateria::AMateria(string const & type): type(type)
{
	cout << "AMateria: Constructor called" << endl;
}

AMateria::AMateria(const AMateria &materia)
{
	cout << "AMateria: Copy constructor called" << endl;
	*this = materia;
}

AMateria &AMateria::operator = (const AMateria &materia)
{
	cout << "AMateria: Copy assignment operator called" << endl;
	if (this == &materia)
		return (*this);
	this->type = materia.type;
	return (*this);
}

AMateria::~AMateria()
{
	cout << "AMateria: Destructor called" << endl;
}

string const &AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	cout << "AMateria: skill used at" << &target << endl;
}