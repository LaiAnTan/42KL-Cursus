#include "DiamondTrap.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

DiamondTrap::DiamondTrap()
{
	cout << "DiamondTrap: Default Construtor Called" << endl;
	ClapTrap::hitPoints = FragTrap::hitPoints;
	ClapTrap::energyPoints = ScavTrap::energyPoints;
	ClapTrap::attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(string name)
{
	cout << "DiamondTrap: Counstructor Called" << endl;
	this->name = name;
	ClapTrap::name = name.append("_clap_name");
	ClapTrap::hitPoints = FragTrap::hitPoints;
	ClapTrap::energyPoints = ScavTrap::energyPoints;
	ClapTrap::attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap): ClapTrap(), ScavTrap(), FragTrap()
{
	*this = diamondtrap;
}

DiamondTrap &DiamondTrap::operator = (const DiamondTrap &diamondtrap)
{
	if (this == &diamondtrap)
		return (*this);
	this->ClapTrap::name = diamondtrap.ClapTrap::name;
	this->name = diamondtrap.name;
	ClapTrap::hitPoints = diamondtrap.ClapTrap::hitPoints;
	ClapTrap::energyPoints = diamondtrap.ClapTrap::energyPoints;
	ClapTrap::attackDamage = diamondtrap.ClapTrap::attackDamage;
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
	cout << name << ": HP - " << ClapTrap:: hitPoints << " ATK - " << ClapTrap::attackDamage << " EP - " << ClapTrap::energyPoints << endl; 
}