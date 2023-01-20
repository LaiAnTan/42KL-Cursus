#include "Zombie.hpp"

void	randomChump(string name)
{
	Zombie randomChump;
	randomChump.setName(name);
	randomChump.announce();
}