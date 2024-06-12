#pragma once

#ifndef ATARGET
#define ATARGET

#include <string>

using std::string;

class ASpell;


class ATarget
{
	public:
		ATarget &operator = (const ATarget &copy);
		virtual ~ATarget();
		virtual ATarget* clone(void) const = 0;

		const string getType(void) const;
		void getHitBySpell(const ASpell &spell) const;

	protected:
		ATarget();
		ATarget(string type);
		ATarget(const ATarget &copy);
		
		string type;
};

#endif