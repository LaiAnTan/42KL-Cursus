#pragma once

#ifndef CHARACTER_HPP

#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

#include <string>


class Character: public ICharacter
{
	public:
		Character();
		Character(string name);
		Character(const Character &character);
		Character &operator = (const Character &character);
		~Character();

		string const & getName() const;

		void		equip(AMateria* m);
		AMateria*	unequip(int idx);
		void		use(int idx, ICharacter& target);
	
	private:
		string name;D
		AMateria *inventory[4];
};

#endif