#ifndef CLAPTRAP_HPP

#define CLAPTRAP_HPP

#include <string>

using	std::string;

class ClapTrap
{
	public:
		ClapTrap(string name);
		ClapTrap(const ClapTrap &claptrap);
		ClapTrap &operator = (const ClapTrap &claptrap);
		~ClapTrap();

		void	attack(const string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
	private:
		string	name;
		int		hitPoints;
		int		energyPoints;
		int		attackDamage;
};

#endif