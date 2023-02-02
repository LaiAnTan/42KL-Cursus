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
	this->name = name;
	ClapTrap::name = name.append("_clap_name");
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap): ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap)
{
	*this = diamondtrap;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &diamondtrap)
{
	if (this == &diamondtrap)
		return (*this);
	this->ClapTrap::name = diamondtrap.ClapTrap::name;
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

void	DiamondTrap::whoAmI(void)
{
	cout << "DiamondTrap: Name - " << name << " ClapTrap name - " << ClapTrap::name << endl;
}