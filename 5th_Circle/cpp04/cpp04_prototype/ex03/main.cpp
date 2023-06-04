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

	ICharacter *me = new Character("me");
	AMateria *tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	
	ground = me->unequip(0);
	bob->equip(ground);
	ground = NULL;

	bob->use(0, *me);
	me->use(0, *bob);
	me->use(1, *bob);

	if (ground)
		delete ground;
	delete bob;
	delete me;
	delete src;

	return 0;
}