#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap	amogus("Sus");
	ScavTrap	sus;
	
	sus = amogus;

	sus.attack("Jones");
	sus.takeDamage(5);
	sus.beRepaired(5);
	sus.guardGate();
}