#include "DiamondTrap.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

DiamondTrap::DiamondTrap()
{
	cout << "DiamondTrap: Default Construtor Called" << endl;
}

DiamondTrap::DiamondTrap(string name)
{
	cout << "DiamondTrap: Counstructor Called" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap)
{
	*this = diamondtrap;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &diamondtrap)
{
	if (this == &diamondtrap)
		return (*this);
		this->name = diamondtrap.name;
	this->hitPoints = diamondtrap.hitPoints;
	this->energyPoints = diamondtrap.energyPoints;
	this->attackDamage = diamondtrap.attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	cout << "DiamondTrap: Destructor Called" << endl;
}