#ifndef HUMANA_HPP

#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(string name, Weapon weapon);
		~HumanA();
		void	attack(void);
	private:
		string	name;
		Weapon	wp;
};

#endif