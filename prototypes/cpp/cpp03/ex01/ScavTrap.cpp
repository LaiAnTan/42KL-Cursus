#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

#include <iostream>
#include <string>

using	std::string;
using	std::cout;
using	std::endl;

ScavTrap::ScavTrap(string name): name(name), hitPoints(100), energyPoints(50), attackDamage(20)
{
	cout << "Constructor called" << endl;
}

void	ScavTrap::attack(const string &target) override 
{
	energyPoints -= 1;
	cout << "ScavTrap " << name << " attacks " << target << ", dealing " << attackDamage << " points of damage!" << endl;
}

void	ScavTrap::takeDamage(unsigned int amount) override
{
	hitPoints -= amount;
	cout << "ScavTrap " << name << " was hit for " << amount << " points of damage!" << endl;
}

void	ScavTrap::beRepaired(unsigned int amount) override
{
	energyPoints -= 1;
	hitPoints += amount;
	cout << "ScavTrap " << name << " repairs itself for " << amount << " points of health!" << endl;
}