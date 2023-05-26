#include "Zombie.hpp"

int	main(void)
{
	Zombie* zH = zombieHorde(8, "Justin");

	for (int i = 0; i < 8; i++)
		zH[i].announce();

	delete[] zH;
}