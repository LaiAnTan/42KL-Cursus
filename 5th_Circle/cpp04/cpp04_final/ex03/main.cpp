#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"


// still needs to test unequip and inventory full equip functions
#include <iostream>

int main()
{
	IMateriaSource *src = new MateriaSource();
	AMateria *ground;

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *Wally = new Character("Wally");
	AMateria *tmp;

	tmp = src->createMateria("ice");
	Wally->equip(tmp);
	tmp = src->createMateria("cure");
	Wally->equip(tmp);
	ICharacter *bob = new Character("bob");
	
	ground = Wally->unequip(0);
	bob->equip(ground);
	ground = NULL;

	bob->use(0, *Wally);
	Wally->use(0, *bob);
	Wally->use(1, *bob);

	if (ground)
		delete ground;
	delete bob;
	delete Wally;
	delete src;

	return 0;
}