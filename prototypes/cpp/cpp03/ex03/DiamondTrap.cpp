#include "DiamondTrap.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

DiamondTrap::DiamondTrap()
{
	cout << "DiamondTrap: Default Construtor Called" << endl;
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(string name)
{
	cout << "DiamondTrap: Counstructor Called" << endl;
	this->name = name;
	ClapTrap::name = name.append("_clap_name");
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap): ClapTrap(), ScavTrap(), FragTrap()
{
	*this = diamondtrap;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &diamondtrap)
{
	if (this == &diamondtrap)
		return (*this);
	this->name = diamondtrap.name;
	this->name = diamondtrap.name;
	hitPoints = diamondtrap.hitPoints;
	energyPoints = diamondtrap.energyPoints;
	attackDamage = diamondtrap.attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	cout << "DiamondTrap: Destructor Called" << endl;
}

void	DiamondTrap::whoAmI(void)
{
	cout << "DiamondTrap: Name - " << name << " | ClapTrap name - " << ClapTrap::name << endl;
}

void	DiamondTrap::getStats(void)
{
	cout << name << ": HP - " << hitPoints << " ATK - " << attackDamage << " EP - " << energyPoints << endl; 
}