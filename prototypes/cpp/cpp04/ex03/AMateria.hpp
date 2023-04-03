#pragma once

#ifndef AMATERIA_HPP

#define AMATERIA_HPP

#include "ICharacter.hpp"

#include <string>

using std::string;

class ICharacter;

class AMateria
{
	public:

		AMateria();
		AMateria(string const & type);
		AMateria(const AMateria &materia);
		AMateria &operator = (const AMateria &materia); 
		~AMateria();

		string const &getType() const; // returns the Materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		string type;
};

#endif

