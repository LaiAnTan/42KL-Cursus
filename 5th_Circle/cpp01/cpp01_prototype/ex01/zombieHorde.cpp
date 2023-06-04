#include "Zombie.hpp"

Zombie* zombieHorde(int n, string name)
{
	Zombie* zombieHorde = new Zombie[n];
	for (int i = 0; i < n; i++)
		zombieHorde[i].setName(name);
	return (zombieHorde);
}
