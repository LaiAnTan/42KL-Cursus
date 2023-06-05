#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>
#include <string>

using	std::string;
using	std::cout;
using	std::endl;

ScavTrap::ScavTrap(void): ClapTrap()
{
	cout << "ScavTrap: Default Constructor called" << endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(string name): ClapTrap(name)
{
	cout << "ScavTrap: Constructor called" << endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap): ClapTrap(scavtrap)
{
	cout << "ScavTrap: Copy constructor called" << endl;
	*this = scavtrap;
}

ScavTrap &ScavTrap::operator = (const ScavTrap &scavtrap)
{
	cout << "ScavTrap: Copy assignment operator called" << endl;
	if (this == &scavtrap)
		return (*this);
	this->name = scavtrap.name;
	this->hitPoints = scavtrap.hitPoints;
	this->energyPoints = scavtrap.energyPoints;
	this->attackDamage = scavtrap.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap: Destructor called" << endl;
}

void	ScavTrap::attack(const string &target)
{
	if (energyPoints <= 0)
		cout << "ScavTrap " << name << " tried to attack " << target << ", but it has no energy points!" << endl;
	else if (hitPoints <= 0)
		cout << "ScavTrap " << name << " cannot attack " << target << " because it is dead!" << endl;
	else
	{
		this->ClapTrap::energyPoints -= 1;
		cout << "ScavTrap " << name << " attacks " << target << ", dealing " << attackDamage << " points of damage!" << endl;
	}
}

void	ScavTrap::guardGate(void)
{
	cout << "ScavTrap is now in Gate Keeper mode!" << endl;
}