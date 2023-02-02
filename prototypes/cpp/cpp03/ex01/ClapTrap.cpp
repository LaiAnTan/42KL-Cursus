#include "ClapTrap.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

ClapTrap::ClapTrap()
{
	cout << "ClapTrap: Default constructor called" << endl;
}

ClapTrap::ClapTrap(string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	cout << "ClapTrap: Constructor called" << endl;
}

ClapTrap::ClapTrap(string name, int hitPoints, int energyPoints, int attackDamage): name(name), hitPoints(hitPoints), energyPoints(energyPoints), attackDamage(attackDamage)
{
	cout << "ClapTrap: Constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	cout << "ClapTrap: Copy constructor called" << endl;
	*this = claptrap;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &claptrap)
{
	cout << "ClapTrap: Copy assignment operator called" << endl;
	if (this == &claptrap)
		return (*this);
	this->name = claptrap.name;
	this->hitPoints = claptrap.hitPoints;
	this->energyPoints = claptrap.energyPoints;
	this->attackDamage = claptrap.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap: Destructor called" << endl;
}

void	ClapTrap::attack(const string &target)
{
	energyPoints -= 1;
	cout << "ClapTrap " << name << " attacks " << target << ", dealing " << attackDamage << " points of damage!" << endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	cout << name << " was hit for " << amount << " points of damage!" << endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	energyPoints -= 1;
	hitPoints += amount;
	cout << name << " repairs itself for " << amount << " points of health!" << endl;
}