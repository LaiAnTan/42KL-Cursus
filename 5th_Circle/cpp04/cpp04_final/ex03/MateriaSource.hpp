#pragma once

#ifndef MATERIASOURCE_HPP

#define MATERIASORUCE_HPP

#include <string>
#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &materiasource);
		MateriaSource &operator = (const MateriaSource &materiasource);
		~MateriaSource();
		void learnMateria(AMateria* type);
		AMateria* createMateria(string const & type);
	
	private:
		AMateria *mem[4];
};

#endif