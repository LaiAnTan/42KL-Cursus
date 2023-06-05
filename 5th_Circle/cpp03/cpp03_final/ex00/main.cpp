#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	amogus("Sus");
	ClapTrap	sus;
	
	sus = amogus;

	sus.attack("Jones");
	sus.takeDamage(5);
	sus.beRepaired(5);
	sus.takeDamage(12);
	sus.takeDamage(69420);
	sus.beRepaired(20);
	sus.attack("your mom");
}