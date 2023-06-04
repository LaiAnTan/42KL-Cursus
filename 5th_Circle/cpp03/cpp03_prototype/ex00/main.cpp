#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	amogus("Sus");
	ClapTrap	sus;
	
	sus = amogus;

	sus.attack("Jones");
	sus.takeDamage(5);
	sus.beRepaired(5);
}