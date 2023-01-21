#include "Weapon.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

Weapon::Weapon(string type)
{
	this->type = type;
	cout << type << " was constructed" << endl;
}

Weapon::~Weapon()
{
	cout << type << " was destroyed" << endl;
}

const string	Weapon::getType()
{
	string	&typeRef = type;
	return (typeRef);
}

void	Weapon::setType(string type)
{
	this->type = type;
}