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
		virtual ~AMateria();

		virtual string const &getType() const = 0; // returns the Materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		string type;
};

#endif

