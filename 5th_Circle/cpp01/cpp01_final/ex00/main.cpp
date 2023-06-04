#include "Zombie.hpp"

int	main(void)
{
	Zombie	*z1;

	randomChump("John");
	z1 = newZombie("James");
	z1->announce();
	delete z1;
}