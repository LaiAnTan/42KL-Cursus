#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	amogus("Sus");
	DiamondTrap	sus;
	
	sus = amogus;

	sus.getStats();
	sus.attack("Jones");
	sus.takeDamage(50);
	sus.getStats();
	sus.beRepaired(19);
	sus.getStats();
	sus.whoAmI();
}