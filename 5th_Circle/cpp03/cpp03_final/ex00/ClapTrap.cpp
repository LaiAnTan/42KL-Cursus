#include "ClapTrap.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

ClapTrap::ClapTrap()
{
	cout << "ClapTrap: Default constructor called" << endl;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}


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
	if (energyPoints <= 0)
		cout << "ClapTrap " << name << " tried to attack " << target << ", but it has no energy points!" << endl;
	else if (hitPoints <= 0)
		cout << "ClapTrap " << name << " cannot attack " << target << " because it is dead!" << endl;
	else
	{
		energyPoints -= 1;
		cout << "ClapTrap " << name << " attacks " << target << ", dealing " << attackDamage << " points of damage!" << endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
		cout << name << "'s dead body was attacked for " << amount << " points of damage, but it had no effect!" << endl;
	else
	{
		if (hitPoints <= (int) amount)
			cout << name << " was hit for " << amount << " fatal points of damage, killing it!" << endl;
		else
			cout << name << " was hit for " << amount << " points of damage!" << endl;
		hitPoints -= amount;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
		cout << name << " cannot repair itself because it is dead!" << endl;
	else if (energyPoints <= 0)
		cout << name << " tried to repair itself, but it has no energy points!" << endl;
	else
	{
		energyPoints -= 1;
		hitPoints += amount;
		cout << name << " repairs itself for " << amount << " points of health!" << endl;
	}
}