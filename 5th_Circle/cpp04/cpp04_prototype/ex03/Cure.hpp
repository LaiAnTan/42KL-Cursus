#pragma once

#ifndef CURE_HPP

#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &cure);
		Cure &operator = (const Cure &cure);
		~Cure();

		string const &getType() const;

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif