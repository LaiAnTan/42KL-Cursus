#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP

#include <string>

using	std::string;

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(string name);
		ClapTrap(string name, int hitPoints, int energyPoints, int attackDamage);
		ClapTrap(const ClapTrap &claptrap);
		ClapTrap &operator = (const ClapTrap &claptrap);
		~ClapTrap();

		void	attack(const string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		
	protected:
		string	name;
		int		hitPoints;
		int		energyPoints;
		int		attackDamage;
};

#endif