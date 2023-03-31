#pragma once

#ifndef AMATERIA_HPP

#define AMATERIA_HPP

#include <string>

using std::string;

class AMateria
{
	protected:

	public:
		AMateria(string const & type);
		string const &getType() const; // returns the Materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};



#endif