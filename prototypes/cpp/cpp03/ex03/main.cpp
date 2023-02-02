#include "FragTrap.hpp"

int main(void)
{
	FragTrap	amogus("Sus");
	FragTrap	sus;
	
	sus = amogus;

	sus.attack("Jones");
	sus.takeDamage(5);
	sus.beRepaired(5);
	sus.highFivesGuys();
}