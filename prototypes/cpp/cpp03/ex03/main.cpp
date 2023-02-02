#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	amogus("Sus");
	DiamondTrap	sus;
	
	sus = amogus;

	sus.attack("Jones");
	sus.takeDamage(20);
	sus.beRepaired(10);
	sus.whoAmI();
	sus.getStats();
}