#include "ClapTrap.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

ClapTrap::ClapTrap(string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	cout << "Constructor called" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
	cout << "Copy constructor called" << endl;
	*this = claptrap;
}

ClapTrap &ClapTrap::operator = (const ClapTrap &claptrap)
{
	cout << "Copy assignment operator called" << endl;
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
	cout << "Destructor called" << endl;
}

void	ClapTrap::attack(const string &target)
{

}

void	takeDamage(unsigned int amount);
void	beRepaired(unsigned int amount);