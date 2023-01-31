#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>
#include <string>

using	std::string;
using	std::cout;
using	std::endl;

ScavTrap::ScavTrap(void)
{
	cout << "Default Constructor called" << endl;
}

ScavTrap::ScavTrap(string name): ClapTrap(name, 100, 50, 20)
{
	cout << "Constructor called" << endl;
}

void	ScavTrap::attack(const string &target) 
{
	energyPoints -= 1;
	cout << "ScavTrap " << name << " attacks " << target << ", dealing " << attackDamage << " points of damage!" << endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	cout << "ScavTrap " << name << " was hit for " << amount << " points of damage!" << endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	energyPoints -= 1;
	hitPoints += amount;
	cout << "ScavTrap " << name << " repairs itself for " << amount << " points of health!" << endl;
}

void	ScavTrap::guardGate(void)
{
	cout << "ScavTrap is now in Gate Keeper mode!" << endl;
}