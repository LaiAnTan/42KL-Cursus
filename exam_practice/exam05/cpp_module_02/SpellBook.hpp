#include "ASpell.hpp"

#include <string>
#include <map>

using std::string;
using std::map;

class SpellBook
{
	public:
		SpellBook();
		~SpellBook();

		void learnSpell(ASpell *spell);
		void forgetSpell(string const &spellName);
		ASpell* createSpell(string const &spell);

	private:
		map<string, ASpell*> spellbook;
};