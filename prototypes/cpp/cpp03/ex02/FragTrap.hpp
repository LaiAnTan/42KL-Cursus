#ifndef FRAGTRAP_HPP

#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

using	std::string;

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(string name);
		FragTrap(string name, int hitPoints, int energyPoints, int attackDamage);
		FragTrap(const FragTrap &fragtrap);
		FragTrap &operator = (const FragTrap &fragtrap);
		~FragTrap();

		void	attack(const string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		void	highFivesGuys(void);
		void	getStats(void); //testing purposes
};

#endif