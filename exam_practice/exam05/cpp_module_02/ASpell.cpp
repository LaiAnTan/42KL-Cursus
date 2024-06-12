#include "ASpell.hpp"

ASpell::ASpell()
{
	this->name = "";
	this->effects = "";
}

ASpell::ASpell(string name, string effects)
{
	this->name = name;
	this->effects = effects;
}

ASpell::ASpell(const ASpell &copy)
{
	*this = copy;
}

ASpell &ASpell::operator = (const ASpell &copy)
{
	if (this == &copy)
		return (*this);
	this->name = copy.getName();
	this->effects = copy.getEffects();
	return (*this);
}

ASpell::~ASpell() {}

void ASpell::launch(const ATarget &target)
{
	target.getHitBySpell(*this);
}

const string ASpell::getName(void) const
{
	return (this->name);
}

const string ASpell::getEffects(void) const
{
	return (this->effects);
}

