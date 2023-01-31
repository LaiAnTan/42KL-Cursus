#ifndef SCAVTRAP_HPP

#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

#include <string>

using	std::string;

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(string name);

		void	attack(const string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	guardGate(void);

};

#endif