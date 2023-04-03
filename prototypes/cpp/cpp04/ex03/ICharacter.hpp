#pragma once

#ifndef ICHARACTER_HPP

#define ICHARACTER_HPP

#include "AMateria.hpp"
#include <string>

using std::string;

class AMateria;

class ICharacter
{
	public:

		virtual					~ICharacter() {}
		virtual string const	&getName() const = 0;
		virtual void			equip(AMateria* m) = 0;
		virtual AMateria*		unequip(int idx) = 0;
		virtual void			use(int idx, ICharacter& target) = 0;
};

#endif