#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
	for (std::map<std::string, ASpell*>::iterator it = this->spellbook.begin(); it != this->spellbook.end(); ++it)
		delete it->second;
	this->spellbook.clear();
}

void SpellBook::learnSpell(ASpell *spell)
{
	std::map<string, ASpell*>::iterator it = this->spellbook.find(spell->getName());

	if (it == this->spellbook.end())
		this->spellbook[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(string const &spellName)
{
	std::map<string, ASpell*>::iterator it = this->spellbook.find(spellName);

	if (it != this->spellbook.end())
		this->spellbook.erase(it);
}

ASpell* SpellBook::createSpell(string const &spellName)
{
	std::map<string, ASpell*>::iterator it = this->spellbook.find(spellName);

	if (it != this->spellbook.end())
		return it->second;
	return NULL;
}
