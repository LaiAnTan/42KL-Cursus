#include "HumanB.hpp"

#include <iostream>

using std::cout;
using std::endl;

HumanB::HumanB(string name)
{
	cout << name << " was constructed" << endl;
	this->name = name;
}

HumanB::~HumanB(void)
{
	cout << name << " was destroyed" << endl;
}

void	HumanB::attack(void)
{
	cout << name << " attacks with their " << wp->getType() << endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	wp = &weapon;
}