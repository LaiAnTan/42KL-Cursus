#include "Weapon.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

Weapon::Weapon(string type)
{
	setType(type);
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