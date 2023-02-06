#include "FragTrap.hpp"

int main(void)
{
	FragTrap	amogus("Sus");
	FragTrap	sus;
	
	sus = amogus;

	sus.attack("Jones");
	sus.takeDamage(50);
	sus.beRepaired(10);
	sus.highFivesGuys();
	sus.getStats();
}