#include "Character.hpp"

#include <iostream>

using std::cout;
using std::endl;

Character::Character()
{
	cout << "Character: Default constructor called" << endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(string name): name(name)
{
	cout << "Character: Constructor called" << endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character &character)
{
	cout << "Character: Copy constructor called" << endl;
	*this = character;
}

Character &Character::operator = (const Character &character)
{
	cout << "Character: Copy assignment operator called" << endl;
	if (this == &character)
		return (*this);
	this->name = character.getName();
	for (int i = 0; i < 4; i++)
		this->inventory[i] = character.inventory[i];
	return (*this);
}

Character::~Character()
{
	cout << "Character: Destructor called" << endl;
	for (int i = 0; i < 4; i++)
		delete this->inventory[i];
}

string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] != 0)
			continue;
		this->inventory[i] = m;
		return ;
	}
	cout << "Character: No space left in " << this->name << "'s inventory" << endl;
}

AMateria* Character::unequip(int idx)
{
	AMateria*	dropMateria;

	dropMateria = this->inventory[idx];
	this->inventory[idx] = NULL;
	return (dropMateria);
}

void Character::use(int idx, ICharacter& target)
{
	return (inventory[idx]->use(target));
}