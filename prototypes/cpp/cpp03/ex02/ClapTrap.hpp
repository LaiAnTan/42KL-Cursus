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

		virtual void	attack(const string &target);
		virtual void	takeDamage(unsigned int amount);
		virtual void	beRepaired(unsigned int amount);
	protected:
		string	name;
		int		hitPoints;
		int		energyPoints;
		int		attackDamage;
};

#endif