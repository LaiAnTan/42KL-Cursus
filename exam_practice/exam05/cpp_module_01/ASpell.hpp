#pragma once

#include "ATarget.hpp"

#ifndef ASPELL
#define ASPELL

#include <string>

using std::string;

class ASpell
{
	public:
		ASpell &operator = (const ASpell &copy);
		virtual ~ASpell();
		virtual ASpell* clone(void) const = 0;

		void launch(const ATarget &target);

		const string getName(void) const;
		const string getEffects(void) const;

	protected:
		ASpell();
		ASpell(string name, string effects);
		ASpell(const ASpell &copy);

		string name;
		string effects;
};

#endif