#ifndef FRAGTRAP_HPP

#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

using	std::string;

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(string name);
		FragTrap(const FragTrap &fragtrap);
		FragTrap &operator = (const FragTrap &fragtrap);
		~FragTrap();

		void	attack(const string &target);

		void	highFivesGuys(void);
		
	protected:
		int		hitPoints;
		int		energyPoints;
		int		attackDamage;
};

#endif