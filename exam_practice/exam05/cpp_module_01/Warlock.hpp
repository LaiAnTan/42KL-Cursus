#include "ASpell.hpp"

#include <iostream>
#include <string>
#include <map>

using std::string;

class Warlock
{
	public:
		Warlock(string name, string title);
		~Warlock();

		string getName() const;
		string getTitle() const;

		void setTitle(const string &title);

		void introduce() const;

		void learnSpell(ASpell *spell);
		void forgetSpell(string spellName);
		void launchSpell(string spellName, ATarget &target);

	private:

		Warlock(const Warlock &warlock);
		Warlock& operator = (const Warlock &warlock);

		string name;
		string title;

		std::map<string, ASpell*> spellbook;
};