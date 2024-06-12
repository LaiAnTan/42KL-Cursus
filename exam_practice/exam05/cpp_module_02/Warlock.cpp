#include "Warlock.hpp"

using std::cout;
using std::endl;

Warlock::Warlock(string name, string title)
{
	this->name = name;
	this->title = title;
	cout << this->name << ": This looks like another boring day." << endl;
}

Warlock::~Warlock()
{
	cout << this->name << ": My job here is done!" << endl;
}

Warlock::Warlock(const Warlock &warlock)
{
	*this = warlock;
	
}

Warlock &Warlock::operator = (const Warlock &warlock)
{
	if (this == &warlock)
		return (*this);
	this->name = warlock.getName();
	this->title = warlock.getTitle();
	return (*this);
}


string Warlock::getName() const
{
	return (this->name);
}

string Warlock::getTitle() const
{
	return (this->title);
}

void Warlock::setTitle(const string &title)
{
	this->title = title;
}

void Warlock::introduce() const
{
	// <NAME>: I am <NAME>, <TITLE>!
	cout << this->name << ": I am " << this->name << ", " << this->title << "!" << endl;
}

void Warlock::learnSpell(ASpell *spell)
{
	this->spellbook.learnSpell(spell);
}

void Warlock::forgetSpell(string spellName)
{
	this->spellbook.forgetSpell(spellName);
}

void  Warlock::launchSpell(string spellName, ATarget &target)
{
	ASpell *spell = this->spellbook.createSpell(spellName);
	if (spell)
		spell->launch(target);
}
