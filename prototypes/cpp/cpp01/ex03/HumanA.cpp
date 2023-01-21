#include "HumanA.hpp"

#include <iostream>

using std::cout;
using std::endl;

HumanA::HumanA(string name, Weapon weapon)
{
	this->name = name;
	wp = weapon;
	cout << name << "was constructed" << endl;
}

HumanA::~HumanA(void)
{
	cout << name << "was destroyed" << endl;
}

void	HumanA::attack(void)
{
	cout << name << " attacks with their " << wp.getType() << endl;
}