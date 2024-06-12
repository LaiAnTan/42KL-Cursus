#include "ASpell.hpp"

class Fwoosh: public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		ASpell* clone(void) const;
};