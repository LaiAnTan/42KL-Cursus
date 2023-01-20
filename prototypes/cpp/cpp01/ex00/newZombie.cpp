#include "Zombie.hpp"

Zombie*	newZombie(string name)
{
	Zombie* newZombie = new Zombie();
	newZombie->setName(name);
	return (newZombie);
}