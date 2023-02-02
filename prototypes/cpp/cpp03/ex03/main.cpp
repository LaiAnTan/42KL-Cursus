#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap	amogus("Sus");
	DiamondTrap	sus;
	
	sus = amogus;

	sus.attack("Jones");
	sus.takeDamage(50);
	sus.beRepaired(19);
	sus.whoAmI();
	sus.getStats();
}