#include "ATarget.hpp"

#include <iostream>

using std::cout;
using std::endl;

ATarget::ATarget()
{
	this->type = "";
}

ATarget::ATarget(string type)
{
	this->type = type;
}

ATarget::~ATarget() {}

ATarget &ATarget::operator = (const ATarget &copy)
{
	if (this == &copy)
		return (*this);
	this->type = copy.getType();
	return (*this);
}

ATarget::ATarget(const ATarget &copy)
{
	*this = copy;
}

const string ATarget::getType(void) const
{
	return this->type;
}

#include "ASpell.hpp"

void ATarget::getHitBySpell(const ASpell &spell) const
{
	cout << this->type << " has been " << spell.getEffects() << "!" << endl;
}