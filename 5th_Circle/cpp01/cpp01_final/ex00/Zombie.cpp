#include "Zombie.hpp"

Zombie::~Zombie()
{
	cout << name << " has been destroyed" << endl;
}

void	Zombie::setName(string name)
{
	this->name = name;
}

void	Zombie::announce(void)
{
	cout << name << ": BraiiiiiiinnnzzzZ..." << endl;
}