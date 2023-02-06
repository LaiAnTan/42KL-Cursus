#include "FragTrap.hpp"

#include <iostream>

using	std::cout;
using	std::endl;

FragTrap::FragTrap(): ClapTrap()
{
	cout << "FragTrap: Default Constructor Called" << endl;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(string name): ClapTrap(name)
{
	cout << "FragTrap: Constructor Called" << endl;
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &fragtrap): ClapTrap(fragtrap)
{
	cout << "FragTrap: Copy constructor called" << endl;
	*this = fragtrap;
}

FragTrap &FragTrap::operator = (const FragTrap &fragtrap)
{
	cout << "FragTrap: Copy assignment operator called" << endl;
	if (this == &fragtrap)
		return (*this);
	this->name = fragtrap.name;
	this->hitPoints = fragtrap.hitPoints;
	this->energyPoints = fragtrap.energyPoints;
	this->attackDamage = fragtrap.attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	cout << "FragTrap: Destructor Called" << endl;
}

void	FragTrap::attack(const string &target)
{
	energyPoints -= 1;
	cout << "FragTrap " << name << " attacks " << target << ", dealing " << attackDamage << " points of damage!" << endl;
}

void	FragTrap::highFivesGuys(void)
{
	cout << "FragTrap wants to high five!" << endl;
}