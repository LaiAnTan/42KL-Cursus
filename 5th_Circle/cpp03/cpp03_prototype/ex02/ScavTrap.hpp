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
		ScavTrap(string name, int hitPoints, int energyPoints, int attackDamage);
		ScavTrap(const ScavTrap &scavtrap);
		ScavTrap &operator = (const ScavTrap &scavtrap);
		~ScavTrap();

		virtual void	attack(const string &target);

		void	guardGate(void);

};

#endif