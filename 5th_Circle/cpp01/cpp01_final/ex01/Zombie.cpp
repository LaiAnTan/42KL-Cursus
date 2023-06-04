#include "Zombie.hpp"

Zombie::Zombie(void)
{
	cout << "A zombie was constructed" << endl;
}

Zombie::~Zombie(void)
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