#ifndef SCAVTRAP_HPP

#define SCAVTRAP_HPP
#include "ClapTrap.hpp"

#include <string>

using	std::string;

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(string name);
		void	ScavTrap::attack(const string &target) override;
		
};

#endif