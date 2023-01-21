#ifndef HUMANB_HPP

#define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(string name);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon newWeapon);
	private:
		string	name;
		Weapon	wp;
};

#endif